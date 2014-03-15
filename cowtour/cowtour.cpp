/*
ID: anant901
PROG: cowtour
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

//Globals
int N;
int coordinates[151][2];
bool adjacency[151][151];

double dist(int x1, int y1, int x2, int y2) {
	return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}

void dfs(int* partition, int root_index, int partition_index) {
	//Assign partition_index to the tree originating at root.
	for(int i=0;i<N;i++) {
		if(adjacency[root_index][i]==1 && partition[i]==-1) {
			partition[i]=partition_index;
			dfs(partition, i, partition_index);
		}
	}
}

int main() {
    ofstream fout ("cowtour.out");
    ifstream fin ("cowtour.in");
    fout << fixed << setprecision(6);
    
    //Input
    fin>>N;
    for(int i=0;i<N;i++)
    	fin>>coordinates[i][0]>>coordinates[i][1];
    fin.get();
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int c=fin.get();
            if(c==48) adjacency[i][j]=0; else adjacency[i][j]=1;
        }
        fin.get();
	}

    //Partition into disjoint fields using DFS
    int partition[151];
    for(int i=0;i<N;i++) partition[i]=-1;
    int partition_index=0;	

	for(int i=0;i<N;i++) {
		if(partition[i]==-1) {
			if(partition[i]==-1) {
				partition[i]=partition_index++;
				dfs(partition, i, partition_index-1);
			}
		}
	}

	int num_partitions = partition_index;
	double distance[151][151];

    //Run FW on the graph
    for(int i=0;i<N;i++) {
    	for(int j=0;j<N;j++) {
    		if (i==j) 
    			distance[i][i]=0; 
    		else if(adjacency[i][j]==1)
    			distance[i][j]=dist(coordinates[i][0], coordinates[i][1], coordinates[j][0], coordinates[j][1]);
    		else
    			distance[i][j]=1000000;
    	}
    }

    for(int k=0;k<N;k++) {
    	for(int i=0;i<N;i++) {
    		for(int j=0;j<N;j++) {
    			double dist_ik = distance[i][k];
    			double dist_kj = distance[k][j];
    			double dist_ij = distance[i][j];
    			if (dist_ik + dist_kj < dist_ij)
    				distance[i][j] = dist_ik + dist_kj;
    		}
    	}
    }

    double minimum = 1000000;
    //Find x in P1 & y in P2 such that 
    // dia(x)+dist(x,y)+dia(y) is smallest for all x,y,P1,P2
	int P1, P2;
    for(int p1=0; p1<num_partitions-1;p1++) {
    	for(int p2=p1+1;p2<num_partitions;p2++) {
    		for(int x=0;x<N;x++) {
    			if(partition[x]!=p1) continue;
    			for(int y=0;y<N;y++) {
    				if (partition[y]==p2) {
						double dia_x = 0;
						double dia_y = 0;
						for(int i=0;i<N;i++)
							if(partition[i]==p1 && i!=x && distance[x][i]>dia_x)
								dia_x=distance[x][i];
						for(int i=0;i<N;i++)
							if(partition[i]==p2 && i!=y && distance[y][i]>dia_y)
								dia_y=distance[y][i];
						double dist_xy = dist(coordinates[x][0], coordinates[x][1], coordinates[y][0], coordinates[y][1]);
						if (dia_x+dia_y+dist_xy < minimum) {
							minimum = dia_x+dia_y+dist_xy;
							P1=p1; P2=p2;
						}
					}
    			}
    		}
    	}
    }
    for(int i=0;i<N;i++) {
    	for(int j=0;j<N;j++) {
    		if (partition[i]==partition[j] && distance[i][j]>minimum)
    			minimum = distance[i][j];
    	}
    }
    fout<<minimum<<endl;
    fout.close();
    return 0;
}