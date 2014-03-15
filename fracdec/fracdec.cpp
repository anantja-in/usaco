/*
ID: anant901
PROG: fracdec
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("fracdec.out");
    ifstream fin ("fracdec.in");

    long N,D,pre_dec;
    fin>>N>>D;
    
    pre_dec = N/D;
    if(N%D==0) {
    	fout<<pre_dec<<".0"<<endl; return 0;
    }
    int history[100000][2];
    int history_index = 0;
    history[history_index][0] = N%D;
    bool solved = 0;
    int start_index=0, end_index=0;
    int hash[1000000];
    for(long x=0;x<1000000;x++) hash[x]=-1;

    while(!solved) {
    	// Get the 0
    	history[history_index][0]*=10;
    	history[history_index][1]=history[history_index][0]/D;
    	history_index++;
    	history[history_index][0]=history[history_index-1][0]%D;

    	if(hash[history[history_index-1][0]]>-1) {
    		start_index = hash[history[history_index-1][0]];
			end_index = history_index-1;
			solved = 1;
    	}
    	else {
    		hash[history[history_index-1][0]]=history_index-1;
    	}
    }

    int print_count=0;
    fout<<pre_dec<<'.';
    if (pre_dec == 0) print_count=1; 
    else {
	    while(pre_dec>0) {
	    	print_count++;
	    	pre_dec/=10;
	    }
	}
    print_count++; // For the decimal
    for(int x=0;x<start_index;x++) {
    	if (print_count==76) {
    		fout<<endl;
    		print_count=0;
    	}
    	fout<<history[x][1];
    	print_count++;
    }
    if (!(start_index==end_index-1)) {
    	if (print_count==76) {
    		fout<<endl;
    		print_count=0;
    	}
	    fout<<"(";
	    print_count++;
	    for(int x=start_index;x<end_index;x++) {
	    	if (print_count==76) {
    			fout<<endl;
    			print_count=0;
    		}
	    	fout<<history[x][1];
	    	print_count++;
	    }
	    if (print_count==76) {
    		fout<<endl;
    		print_count=0;
    	}
	    fout<<")";
		print_count++;
	}
	fout<<endl;
    
    fout.close();
    return 0;
}