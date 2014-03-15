/*
ID: anant901
PROG: comehome
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("comehome.out");
    ifstream fin ("comehome.in");

    int N;
    fin>>N;

    double adjacency[56][56];
    for(int x=0;x<55;x++) for(int y=0;y<55;y++) adjacency[x][y]=20000000;
    //for(int x=0;x<55;x++) adjacency[x][x]=0;
    for(int x=0;x<N;x++) {
    	int v1i, v2i;
    	double dist;
    	char v1,v2;
    	fin>>v1>>v2>>dist;
    	if(int(v1)>=97) v1i=int(v1)-97+26;
    	else v1i=int(v1)-65;
    	if(int(v2)>=97) v2i=int(v2)-97+26;
    	else v2i=int(v2)-65;
    	if (adjacency[v1i][v2i]>dist) {
	    	adjacency[v1i][v2i]=dist;
	    	adjacency[v2i][v1i]=dist;
    	}
    }

    for(int v=0;v<52;v++) {
    	for(int x=0;x<52;x++) {
    		for(int y=0;y<52;y++) {
    			if (adjacency[x][v]+adjacency[y][v] < adjacency[x][y]) {
    				adjacency[x][y] = adjacency[x][v]+adjacency[y][v];
    				adjacency[y][x] = adjacency[x][v]+adjacency[y][v];
    			}
    		}
    	}
    }
    
    double min_dist = 20000000;
    char min_dist_barn;
    for(int x=0;x<25;x++) {
    	if(adjacency[25][x]<min_dist) {
    		min_dist = adjacency[25][x];
    		min_dist_barn = char(x+65);
    	}
    }

    fout<<min_dist_barn<<" "<<min_dist<<endl;
    
    fout.close();
    return 0;
}