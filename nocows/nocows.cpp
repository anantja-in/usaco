/*
ID: anant901
PROG: nocows
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

long long arr[205][105];

int main() {
    ofstream fout ("nocows.out");
    ifstream fin ("nocows.in");
    int N,K;
    fin>>N>>K;
    for(int i=0;i<=N;i++) for(int j=0;j<=K;j++)
    	arr[i][j]=0;
    arr[1][1] = 1;
    for(int i=2;i<=N;i++) arr[i][1]=0;

    for(int n=2;n<=N;n++) {
        for(int k=2;k<=K;k++) {
            // Calculate for (n,k)
            arr[n][k] = 0;
            if (n+1>=2*k && n%2==1) {
                int d = 0;
                int diff = 0;
                for(int i=1; i<=(n-1)/2;i++) {
                    int n1 = i;
                    int n2 = n-i-1;
                    d = arr[n][k];
                    for(int j=1;j<k-1;j++) {
                        arr[n][k] += arr[n1][j] * arr[n2][k-1];
                        arr[n][k] += arr[n1][k-1] * arr[n2][j];
                        arr[n][k] %= 9901;
                    }
                    arr[n][k] += arr[n1][k-1] * arr[n2][k-1];
                    if (n%2==1 && n1==(n-1)/2) diff = arr[n][k]-d;

                }
                arr[n][k]*=2;
                arr[n][k]-= diff;
                arr[n][k]%=9901;
            }
        }
    }
    fout<<arr[N][K]<<endl;
    fout.close();
    return 0;
}