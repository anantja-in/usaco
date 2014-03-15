/*
ID: anant901
PROG: inflate
LANG: C++
*/

/*
Line 1:	M, N: contest minutes and number of problem classes
Lines 2-N+1:	 Two integers: the points and minutes for each class
*/

/*Knapsack problem*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int t[10001];
int max(int a,int b){
    return a>b?a:b;
}

int main() {
    ofstream fout ("inflate.out");
    ifstream fin ("inflate.in");

    int n,m,p,len;
    fin>>n>>m;

    for(int i=0;i!=m;i++)
    {
        fin >> p >> len;
        for(int j=len;j<=n;j++)
            t[j] = max(t[j],t[j-len]+p);
    }
    fout << t[n] << endl;
    fout.close();
    return 0;
}
