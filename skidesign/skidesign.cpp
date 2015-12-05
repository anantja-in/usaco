/*
ID: anant901
PROG: skidesign
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int compare (const void *a, const void *b){
	return ( *(int*)a - *(int*)b );
}

int square(long x) {
	return x*x;
}

int main() {
    ofstream fout ("skidesign.out");
    ifstream fin ("skidesign.in");

    int N, hills[1000];
    fin>>N;
    for(int x=0;x<N;x++) {
    	fin>>hills[x];
    }

		qsort(hills, N, sizeof(int), compare);

		long best_cost = 1000000000;
		for(int mh=hills[0]; mh<=hills[N-1]-17; mh++) {
			long cost = 0;
			for(int x=0; x<N;x++){
				if (hills[x]<mh) {
					cost += square(mh-hills[x]);
				}
				else if (hills[x]>(mh+17)) {
					cost += square(hills[x] - (mh+17));
				}
			}
			if(cost < best_cost) {
				best_cost = cost;
			}
		}

    fout<<best_cost<<endl;
    fout.close();
    return 0;
}
