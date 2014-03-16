/*
ID: anant901
PROG: stamps
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    ofstream fout ("stamps.out");
    ifstream fin ("stamps.in");


    int K,N, stamps[51];
    const long INF =2000005;
    fin>>K>>N;
    for(int x=0;x<N;x++) fin>>stamps[x];

    int arr[INF];

    for(long i=0;i<INF;i++) arr[i]=K+1;

    arr[0]=0;


    for(int x=0;x<N;x++)//for every stamp value
      for(long i=0;i<INF;i++) //for every known value
        if(arr[i]<K)
          if(arr[i+stamps[x]]>(arr[i]+1))
            arr[i+stamps[x]] = arr[i]+1;

    long max = 0;
    long cur = 0;
    for(long i=1;i<INF;i++) {
      if(arr[i]>0 && arr[i]<=K) {
        cur+=1;
        if(cur>max) max=cur;
      }
      else {
        cur=0;
      }
    }

    fout<<max<<'\n';


    fout.close();
    return 0;
}
