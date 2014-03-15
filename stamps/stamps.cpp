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
    fin>>K>>N;
    for(int x=0;x<N;x++) fin>>stamps[x];

    

    
    fout.close();
    return 0;
}