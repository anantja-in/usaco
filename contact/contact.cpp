/*
ID: anant901
PROG: contact
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int compare(pair<int, string>& a, pair<int,string>& b){
	return a.first > b.first;
}

int val(string a){
	int res = 0;
	int pow = 1;
	for(int x=a.length()-1; x>=0; x--){
		if(a[x]=='1') res += pow;
		pow *= 2;
	}
	return res;
}

bool compare_strings(string &a, string &b) {
	if(a.length() == b.length()) return val(a)<val(b);
	else return a.length()<b.length();
}

string format(string s) {
	vector <string> strings;
	string temp="";
	for(int x=0; x<s.length(); x++) {
		if(s[x] == ' ') {
			strings.push_back(temp);
			temp = "";
		}
		else {
			temp += s[x];
		}
	}
	strings.push_back(temp);
	sort(strings.begin(), strings.end(), compare_strings);

	string f="";
	for(int x=0; x<strings.size(); x++) {
		if(x>0){
			if(x%6==0){
				f+='\n';
			}
			else {
				f+=' ';
			}
		}
		f+=strings[x];
	}

	return f;
}

int main() {
    ofstream fout ("contact.out");
    ifstream fin ("contact.in");
		int A,B,N;
		fin>>A>>B>>N;

		string stream="", line;
		while(getline(fin, line)) stream += line;

		map <string,int> freq;

		for(long x=A-1; x<stream.length(); x++) {
			for(int y=x-B+1; y<=x-A+1; y++) {
				if(y<0) continue;
				// look at stream[y] to stream[x]
				string temp = stream.substr(y, x-y+1);
				if(freq.find(temp) != freq.end()) {
					freq[temp] += 1;
				}
				else {
					freq[temp] = 1;
				}
			}
		}

		map <int, string> reverse_freq;

		for(map<string,int>::iterator it=freq.begin(); it!=freq.end(); ++it) {
			if(reverse_freq.find(it->second) != reverse_freq.end()) {
				reverse_freq[it->second] += " ";
				reverse_freq[it->second] += it->first;
			}
			else {
				reverse_freq[it->second] = it->first;
			}
		}

		vector< pair<int,string> > pairs;
		for(map<int,string>::iterator itr = reverse_freq.begin(); itr!=reverse_freq.end(); ++itr)
			pairs.push_back(*itr);

		sort(pairs.begin(), pairs.end(), compare);

		if(pairs.size()<N) N=pairs.size();
    for(int x=0; x<N; x++) {
			fout<<pairs[x].first<<endl<<format(pairs[x].second)<<endl;
		}
		fout.close();
    return 0;
}
