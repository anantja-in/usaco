/*
ID: anant901
PROG: numtri
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int max(int a, int b) {
	return (a>b)?a:b;
}

int main() {
    ofstream fout ("numtri.out");
    ifstream fin ("numtri.in");
    int N;
    fin>>N;
    int arr[1005][1005];
    for(int i=0;i<N;i++)
    	for(int j=0;j<=i;j++)
    		fin>>arr[i][j];
    for(int i=N-2;i>=0;i--)
    	for(int j=0;j<=N;j++)
    		arr[i][j]=arr[i][j]+max(arr[i+1][j], arr[i+1][j+1]);
    fout<<arr[0][0]<<endl;
    return 0;
}