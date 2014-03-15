/*
ID: anant901
PROG: sort3
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int mini(int a, int b) {
	return (a<b)?a:b;
}

int main() {
    ofstream fout ("sort3.out");
    ifstream fin ("sort3.in");
    
    int records[1005];
    int N;
    fin>>N;

    for(int i=0;i<N;i++) {
    	fin>>records[i];
    }
    int ones=0;
    int twos=0;
    int threes=0;
    for(int i=0;i<N;i++) {
    	switch(records[i]) {
    		case 1: ones++; break;
    		case 2: twos++; break;
    		case 3: threes++; break;
    	}
    }
    int matrix[3][3];
    for(int i=0;i<3;i++) for(int j=0;j<3;j++) matrix[i][j]=0;
    for(int i=0;i<ones;i++) {
    	switch(records[i]) {
    		case 1: matrix[0][0]++; break;
    		case 2: matrix[0][1]++; break;
    		case 3: matrix[0][2]++; break;
    	}
    }
    for(int i=ones;i<ones+twos;i++) {
    	switch(records[i]) {
    		case 1: matrix[1][0]++; break;
    		case 2: matrix[1][1]++; break;
    		case 3: matrix[1][2]++; break;
    	}
    }
    for(int i=ones+twos;i<ones+twos+threes;i++) {
    	switch(records[i]) {
    		case 1: matrix[2][0]++; break;
    		case 2: matrix[2][1]++; break;
    		case 3: matrix[2][2]++; break;
    	}
    }
    

    int answer = 0;
    int i,j;

    i=0; j=1;
    if (matrix[i][j]>0 && matrix[j][i]>0) {
    	int min = mini(matrix[i][j], matrix[j][i]);
    	answer+=min; matrix[i][j]-=min; matrix[j][i]-=min;
    }

    i=0; j=2;
    if (matrix[i][j]>0 && matrix[j][i]>0) {
    	int min = mini(matrix[i][j], matrix[j][i]);
    	answer+=min; matrix[i][j]-=min; matrix[j][i]-=min;
    }

    i=1; j=2;
    if (matrix[i][j]>0 && matrix[j][i]>0) {
    	int min = mini(matrix[i][j], matrix[j][i]);
    	answer+=min; matrix[i][j]-=min; matrix[j][i]-=min;
    }

    i=matrix[0][2]+matrix[2][0];
    answer+=i*2;
    fout<<answer<<endl;

    fout.close();
    return 0;
}