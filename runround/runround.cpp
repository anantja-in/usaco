/*
ID: anant901
PROG: runround
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int is_runround(long long n) {
	int arr[25];
	int len=0;
	while(n>0) {
		arr[len++]=n%10;
		n/=10;
	}
	for(int x=0;x<len;x++) if(arr[x]==0) return 0;
	int digits[10]; for(int x=0;x<10;x++) digits[x]=0;
	for(int x=0;x<len;x++) digits[arr[x]]+=1;
	for(int x=0;x<10;x++) if(digits[x]>1) return 0;
	for(int x=0;x<len/2;x++) {
		int temp = arr[x];
		arr[x]=arr[len-x-1];
		arr[len-x-1]=temp;
	}
	int visited[25];
	for(int x=0;x<25;x++) visited[x]=0;
	int cur = arr[0]%len;
	int moves = 0;
	while(!visited[0] && moves<=len) {
		moves++;
		visited[cur] += 1;
		cur += arr[cur];
		cur %= len;
	}
	int is_runround = 1;

	for(int x=0;x<len;x++) {
		if(visited[x]!=1) {
			is_runround=0;
			break;
		}
	}

	return is_runround;
}

int main() {
    ofstream fout ("runround.out");
    ifstream fin ("runround.in");
    long long N;
    fin>>N;
    bool found = 0;
    while(!found) {
    	N++;
    	if (is_runround(N)) { 
    		fout<<N<<endl;
    		found = 1;
    	}
    }
    fout.close();
    return 0;
}