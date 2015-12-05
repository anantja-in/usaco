/*
ID: anant901
PROG: combo
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

int cap(int a, int limit){
	if (a>limit) return limit; else return a;
}

void swap(int &a, int &b) {
	a+=b;
	b=a-b;
	a=a-b;
}

int main() {
    ofstream fout ("combo.out");
    ifstream fin ("combo.in");
    
    int N, a1, a2, a3, b1, b2, b3;
    fin>>N>>a1>>a2>>a3>>b1>>b2>>b3;

    int total = cap(N,5) * cap(N,5) * cap(N,5) * 2;
    int overlap1=0, overlap2=0, overlap3=0, count=0;
    set<int> overlap;

    for(count=0 ; count<5; count++) {
    	overlap.insert((a1-2+count+N)%N+1);
    	overlap.insert((b1-2+count+N)%N+1);
    }
    overlap1 = cap(N,5)*2 - overlap.size();
    overlap.clear();
    for(count=0 ; count<5; count++) {
    	overlap.insert((a2-2+count+N)%N+1);
    	overlap.insert((b2-2+count+N)%N+1);
    }
    overlap2 = cap(N,5)*2 - overlap.size();
    overlap.clear();
    for(count=0 ; count<5; count++) {
    	overlap.insert((a3-2+count+N)%N+1);
    	overlap.insert((b3-2+count+N)%N+1);
    }
    overlap3 = cap(N,5)*2 - overlap.size();
    overlap.clear();

    total = total - overlap1*overlap2*overlap3;
    fout << total << endl;
    fout.close();
    return 0;
}