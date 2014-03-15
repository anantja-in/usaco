/*
ID: anant901
PROG: money
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("money.out");
    ifstream fin ("money.in");

    int V,N;
    fin>>V>>N;
    int vals[30];
    for(int x=0;x<V;x++) fin>>vals[x]; //Assume it's sorted

    long long ways[10005];
	for(int x=0;x<=N;x++) ways[x]=0;
	ways[0]=1;
	for(int i=0;i<V;i++) {
		for(int j=vals[i];j<=N;j++) {
			ways[j]+=ways[j-vals[i]];
		}
	}
	//for(int x=0;x<=N;x++) cout<<x<<" "<<ways[x]<<endl;
	fout<<ways[N]<<endl;
    fout.close();
    return 0;
}