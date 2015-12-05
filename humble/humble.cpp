/*
ID: anant901
PROG: humble
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    ofstream fout ("humble.out");
    ifstream fin ("humble.in");

    int K,N;
		fin>>K>>N;
		int S[K], M[K];
		long H[N+1];
    for (int i=0;i<K;i++) fin>>S[i];
		memset(M, 0, sizeof(M));
		H[0]=1;

		int pos = 0;
		while(pos < N+1){
			long next = 2147483647;
      vector<int> which;
      for(int i = 0; i < K; i++){
      	long sol = S[i] * H[M[i]];
        if(sol > H[pos] && sol <= next){
        	if(sol < next){
          	next = sol;
           	which.resize(1);
            which[0] = i;
         	}
          else if(sol == next){
          	which.push_back(i);
          }
        }
      }
      H[++pos] = next;
      for(int i = 0; i < which.size(); i++) M[which[i]]++;
		}

		fout<<H[N]<<endl;
    fout.close();
    return 0;
}
