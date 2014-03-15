/*
ID: anant901
PROG: checker
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <stack>

using namespace std;
int N;
int total=0;
bool queens[15][15];
//stack <string> solution;
ofstream fout ("checker.out");

int canplacequeen(int row, int column) {
	for(int i=0;i<N;i++) {
		if(queens[row][i]) return 0;
		if(queens[i][column]) return 0;
		if(row+i<N && column+i<N)
			if(queens[row+i][column+i]) return 0;
		if(row-i>=0 && column+i<N)
			if(queens[row-i][column+i]) return 0;
		if(row-i>=0 && column-i>=0)
			if(queens[row-i][column-i]) return 0;
		if(row+i<N && column-i>=0)
			if(queens[row+i][column-i]) return 0;
	}
	return 1;
}

string toStr(long long n) {
	string s = "";
	while(n>0){
		s=char(n%10+'0')+s;
		n/=10;
	}
	return s;
}

void placequeen(int column) { //place columns 0..max-1
	//cout<<"Placequeen: column: "<<column<<endl;
	if (column == N) { 
		total+=1;
		if(total<=3) {
			string s="";
			for(int i=0;i<N;i++) {
				for(int j=0;j<N;j++) {
					if(queens[j][i]==1)
						s+=toStr(j+1);
				}
				if(i!=N-1)
					s+=' ';
			}
			fout<<s<<endl;
			cout<<"Solution #"<<total<<": "<<s<<endl;
		}
	}
    for (int row = 0; row < N; row++)  {
        if (canplacequeen(row,column)) {
			//mark queen placed at column,row;
			queens[row][column]=1;
			placequeen(column+1);
			//un-mark queen placed at column,row;
			queens[row][column]=0;
    	}
    }
}

int main() {
    ifstream fin ("checker.in");
    fin>>N;
    for(int i=0;i<15;i++) {
    	for(int j=0;j<15;j++) queens[i][j]=0;
    }
    placequeen(0);
    
    fout<<total<<endl;
    fout.close();
    return 0;
}