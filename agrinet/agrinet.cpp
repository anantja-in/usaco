/*
ID: anant901
PROG: agrinet
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#define INFINITY 1000000

using namespace std;

int main() {
    ofstream fout ("agrinet.out");
    ifstream fin ("agrinet.in");

    int N;
    long grid[101][101];

    fin>>N;
    for(int x=0;x<N;x++) for(int y=0;y<N;y++) fin>>grid[x][y];

    long distance[101];
	bool intree[101];
	for(int x=0;x<N;x++) {
		distance[x]= INFINITY;
		intree[x] = 0;
	}

	int treesize = 1;
	long treecost = 0;
	intree[0]=1;

	for(int x=0;x<N;x++) distance[x] = grid[0][x];

	while(treesize<N) {
		long minimum_dist = INFINITY;
		int minimum_dist_node = -1;
		
		for(int x=0;x<N;x++) {
			if(!intree[x] && distance[x]<minimum_dist) {
				minimum_dist = distance[x];
				minimum_dist_node = x;
			}
		}
		
		treesize++;
		treecost+=minimum_dist;
		intree[minimum_dist_node]=1;

		for(int x=0;x<N;x++)
			if(distance[x]>grid[minimum_dist_node][x])
				distance[x] = grid[minimum_dist_node][x];
	}

	fout<<treecost<<endl;
     
    fout.close();
    return 0;
}