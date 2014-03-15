/*
ID: anant901
PROG: subset
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
long long cache[8000][40];

long long rec(int n, int k) {
	if (n<0 || k<0) return 0;
	if (n==0 && k==0)
		return 1;
	else if (cache[n][k]==-1)
		cache[n][k]=rec(n,k-1)+rec(n-k,k-1);
	return cache[n][k];
}

int main() {
    ofstream fout ("subset.out");
    ifstream fin ("subset.in");
    int N;
    fin>>N;
    int total = (N*(N+1))/2;
    for(int x=0;x<8000;x++) for(int y=0;y<40;y++) cache[x][y]=-1;
    if (total%2==0) {
    	fout<<rec(total/2, N)/2<<endl;
    }
    else {
    	fout<<0<<endl;
    }
    fout.close();
    return 0;
}