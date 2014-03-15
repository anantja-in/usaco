/*
ID: anant901
PROG: maze1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("maze1.out");
    ifstream fin ("maze1.in");

    int W, H;
    int distance[3801];
    bool visited[3801];
    int adjacency[3801][4]; //Degree max is 4
    int start_vertex[2]; int start_vertex_index=0;

    fin>>W>>H;

    for(int i=0; i<W*H;i++) {
    	distance[i] = 10000;
    	visited[i] = 0;
    	for(int j=0;j<4;j++)
    		adjacency[i][j]=-1;
    }

    char grid[201][80];
    fin.get(); //To skip the newline character
    for (int i=0;i<2*H+1;i++) {
    	for(int j=0;j<2*W+1;j++) {
    		grid[i][j]=fin.get();
    	}
    	fin.get(); //To skip the newline character
    }
    

    for (int i=0;i<H;i++) {
    	for(int j=0;j<W;j++) {
    		int index = i*W+j;

    		int grid_x = 2*i+1;
    		int grid_y = 2*j+1;
    		int adjacency_index = 0;

    		if (grid[grid_x-1][grid_y] == ' ')
    			if (i==0)
    				start_vertex[start_vertex_index++] = index;
    			else
    				adjacency[index][adjacency_index++] = index-W;

    		if (grid[grid_x+1][grid_y] == ' ')
    			if (i==H-1)
    				start_vertex[start_vertex_index++] = index;
    			else
    				adjacency[index][adjacency_index++] = index+W;

    		if (grid[grid_x][grid_y-1] == ' ')
    			if(j==0)
    				start_vertex[start_vertex_index++] = index;
    			else
    				adjacency[index][adjacency_index++] = index-1;

    		if (grid[grid_x][grid_y+1] == ' ')
    			if(j==W-1)
    				start_vertex[start_vertex_index++] = index;
    			else
    				adjacency[index][adjacency_index++] = index+1;
    	}
    }

    // First run with start_vertex[0]
    distance[start_vertex[0]] = 1;
    int nodesvisited = 1;

    while(nodesvisited<W*H) {
    	int min_dist_unvisited = -1;
    	int min_dist = 10000;
    	for(int i=0;i<H*W;i++) {
    		if (!visited[i]) {
    			if(distance[i]<min_dist) {
    				min_dist=distance[i];
    				min_dist_unvisited = i;
    			}
    		}
    	}
    	visited[min_dist_unvisited] = 1;
    	for(int i=0;i<4;i++) {
    		if (adjacency[min_dist_unvisited][i]>=0) {
    			// a neighbour index exists
    			int neighbour = adjacency[min_dist_unvisited][i];
    			if(!visited[neighbour]) {
	    			if(min_dist+1 < distance[neighbour]) {
	    				distance[neighbour] = min_dist+1;
	    			}
    			}
    		}
    	}
    	nodesvisited +=1;
    }

    //Copy over these distances
    int distance_first_vertex[3801];
    for(int i=0;i<W*H;i++) {
    	distance_first_vertex[i]=distance[i];
    }

    // Check for 2nd vertex
    for(int i=0; i<W*H;i++) {
    	distance[i] = 10000;
    	visited[i] = 0;
    }
    distance[start_vertex[1]] = 1;
    nodesvisited = 1;

    while(nodesvisited<W*H) {
    	int min_dist_unvisited = -1;
    	int min_dist = 10000;
    	for(int i=0;i<H*W;i++) {
    		if (!visited[i]) {
    			if(distance[i]<min_dist) {
    				min_dist=distance[i];
    				min_dist_unvisited = i;
    			}
    		}
    	}
    	visited[min_dist_unvisited] = 1;
    	for(int i=0;i<4;i++) {
    		if (adjacency[min_dist_unvisited][i]>=0) {
    			// a neighbour index exists
    			int neighbour = adjacency[min_dist_unvisited][i];
    			if(!visited[neighbour]) {
	    			if(min_dist+1 < distance[neighbour]) {
	    				distance[neighbour] = min_dist+1;
	    			}
    			}
    		}
    	}
    	nodesvisited +=1;
    }

    // Update the distance table to include vertex 1 distances
    for(int i=0;i<W*H;i++)
    	if(distance_first_vertex[i]<distance[i])
    		distance[i]=distance_first_vertex[i];


    int answer = -1;
    for(int i=0;i<W*H;i++) {
    	if(distance[i]>answer) {
    		answer = distance[i];
    	}
    }

    fout<<answer<<endl;
    fout.close();
    return 0;
}