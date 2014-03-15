/*
ID: anant901
PROG: prefix
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("prefix.out");
    ifstream fin ("prefix.in");
    string primitives[210];
    int i=0;
    do {
    	fin>>primitives[i];
    	i++;
    } while(primitives[i-1].compare(string("."))!=0);
    int num_primitives = i-1;
    //for(int x=0;x<num_primitives;x++) cout<<primitives[x]<<endl;
    string line, sequence;
    while(getline(fin,line))
    	sequence+=line;
    //cout<<sequence.length()<<endl;
    int seq_len = sequence.length();
    long long max[200010];
    for(int x=0;x<seq_len;x++) max[x]=0;
    for(int x=seq_len-1;x>=0;x--) {
    	long long cur_max = 0;
    	// for each primitive, match it at current location
    	for(int p=0;p<num_primitives;p++) {
    		int primitive_len = primitives[p].length();
    		if(x+primitive_len<=seq_len) {
    			if(primitives[p].compare(sequence.substr(x,primitive_len))==0) {
    				// if matched, find out cur_max = primitive_len + max[x+primitive_len]
    				if(primitive_len + max[x+primitive_len]>cur_max)
    					cur_max=primitive_len + max[x+primitive_len];
    			}
    		}
    	}
    	max[x]=cur_max;
    }
    //for(int x=0;x<seq_len;x++)
    //	cout<<max[x]<<endl;
    fout<<max[0]<<endl;
    fout.close();
    return 0;
}