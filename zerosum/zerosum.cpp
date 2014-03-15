/*
ID: anant901
PROG: zerosum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

int main() {
    ofstream fout ("zerosum.out");
    ifstream fin ("zerosum.in");
    int N;
    fin>>N;

    int patterns[7000][10];
    // Work in N-1 bits. Generate 3^N patterns
    for(int x=0;x<pow(3,N-1);x++) {
    	int number = x;
    	int i = N-2;
    	while(i>=0) {
    		patterns[x][i--]=number%3;
    		number/=3;
    	}
    }
    for(int x=0;x<pow(3,N-1);x++) {
    	int numbers[10];
    	numbers[0]=1;
    	int prev = 0;
    	bool signs [10]; // true means add, false means subtract
    	for(int y=0;y<N-1;y++) {
    		if(patterns[x][y]==0) {
    			// a space, next digit is y+2
    			numbers[prev]*=10;
    			numbers[prev]+=(y+2);
    		}
    		else if (patterns[x][y]==1) {
    			// a plus
    			numbers[prev+1]=y+2;
    			signs[prev] = 1;
    			prev++;
    		}
    		else {
    			// a minus
    			numbers[prev+1]=y+2;
    			signs[prev] = 0;
    			prev++;
    		}
    	}
    	/*
    	for(int j=0;j<N-1;j++) cout<<patterns[x][j]<<" ";
    	cout<<endl;
    	for(int j=0;j<=prev;j++) cout<<numbers[j]<<" ";
    	cout<<endl;
   	 	for(int j=0;j<=prev;j++) cout<<signs[j]<<" ";
    	cout<<endl;
    	*/
    	long answer = numbers[0];
    	for(int i=1;i<=prev;i++) {
    		if(signs[i-1]) {
    			answer+=numbers[i];
    		}
    		else 
    			answer-=numbers[i];
    	}
    	//cout<<"Answer: "<<answer<<endl;
    	if (answer==0) {
    		for(int i=0;i<N;i++) {
    			fout<<i+1;
    			if(i!=N-1) {
	    			switch(patterns[x][i]) {
	    				case 0: fout<<" "; break;
	    				case 1: fout<<"+"; break;
	    				case 2: fout<<"-"; break;
	    			}
    			}
    		}
    		fout<<endl;
    	}
    }
    fout.close();
    return 0;
}