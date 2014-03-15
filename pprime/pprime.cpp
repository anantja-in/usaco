/*
ID: anant901
PROG: pprime
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

bool is_prime(long long n) {
	if(n%2==0) return 0;
	for(long long i=3; i<=sqrt(n); i++) {
		if(n%i==0) return 0;
	}
	return 1;
}

string toStr(long long n) {
	string s = "";
	while(n>0){
		s+=char(n%10+'0');
		n/=10;
	}
	return s;
}

/*
bool is_palindrome(long long n) {
	string s = toStr(n);
	for(int i=0; i<s.length()/2; i++) {
		if(s[i]!=s[s.length()-1-i]) return 0;
	}
	return 1;
}
*/

bool do_palindrome(long long n, long long start, long long end) {
	if(n<start) return 0;
	if(n>end) return 0;
	if(is_prime(n)) return 1;
	return 0;
}

int main() {
    ofstream fout ("pprime.out");
    ifstream fin ("pprime.in");
    long long start, end;
    fin>>start>>end;

    /*
    for (long long i=start; i<=end; i++) {
    	if(is_palindrome(i))
    		if(is_prime(i))
    			fout<<i<<endl;
    }
    */
    int min_len = toStr(start).length();
    int max_len = toStr(end).length();

    for (int len=min_len; len<=max_len; len++) {
    	switch(len) {
    		case 1:
    			for(int d1=1; d1<=9; d1++) {
    				long long palindrome = d1;
    				if(do_palindrome(palindrome, start, end)) fout<<palindrome<<endl;
    			}
    		break;
    		case 2:
    			for(int d1=1; d1<=9; d1++) {
    				long long palindrome = 10*d1+d1;
    				if(do_palindrome(palindrome, start, end)) fout<<palindrome<<endl;
    			}
    		break;
    		case 3:
    			for (int d1 = 1; d1 <= 9; d1+=2) {	/* only odd; evens aren't so prime */    
			        for (int d2 = 0; d2 <= 9; d2++) {
				    	long long palindrome = 100*d1 + 10*d2 + d1;
				    	if(do_palindrome(palindrome, start, end)) fout<<palindrome<<endl;
					}
				}
    		break;
    		case 4:
    			for (int d1 = 1; d1 <= 9; d1+=2) {	/* only odd; evens aren't so prime */    
			        for (int d2 = 0; d2 <= 9; d2++) {
				    	long long palindrome = 1000*d1 + 100*d2 + 10*d2 + d1;
				    	if(do_palindrome(palindrome, start, end)) fout<<palindrome<<endl;
					}
				}
    		break;
    		case 5:
	    		for (int d1 = 1; d1 <= 9; d1+=2) {	/* only odd; evens aren't so prime */
				    for (int d2 = 0; d2 <= 9; d2++) {
				        for (int d3 = 0; d3 <= 9; d3++) {
					    	long long palindrome = 10000*d1 + 1000*d2 +100*d3 + 10*d2 + d1;
					    	if(do_palindrome(palindrome, start, end)) fout<<palindrome<<endl;
						}
				    }
				}
    		break;
    		case 6:
    			for (int d1 = 1; d1 <= 9; d1+=2) {	/* only odd; evens aren't so prime */
				    for (int d2 = 0; d2 <= 9; d2++) {
				        for (int d3 = 0; d3 <= 9; d3++) {
					    	long long palindrome = 100000*d1 + 10000*d2 +1000*d3 + 100*d3 + 10*d2 + d1;
					    	if(do_palindrome(palindrome, start, end)) fout<<palindrome<<endl;
						}
				    }
				}
    		break;
    		case 7:
    			for (int d1 = 1; d1 <= 9; d1+=2) {	/* only odd; evens aren't so prime */
				    for (int d2 = 0; d2 <= 9; d2++) {
				        for (int d3 = 0; d3 <= 9; d3++) {
				        	for(int d4 = 0; d4 <= 9; d4++) {
				        		long long palindrome = 1000000*d1 + 100000*d2 +10000*d3 +1000*d4 +100*d3 + 10*d2 + d1;
					    		if(do_palindrome(palindrome, start, end)) fout<<palindrome<<endl;
				        	}
						}
				    }
				}
    		break;
    		case 8:
    			for (int d1 = 1; d1 <= 9; d1+=2) {	/* only odd; evens aren't so prime */
				    for (int d2 = 0; d2 <= 9; d2++) {
				        for (int d3 = 0; d3 <= 9; d3++) {
				        	for(int d4 = 0; d4 <= 9; d4++) {
				        		long long palindrome = 10000000*d1 + 1000000*d2 +100000*d3 +10000*d4 +1000*d4 +100*d3 + 10*d2 + d1;
					    		if(do_palindrome(palindrome, start, end)) fout<<palindrome<<endl;
				        	}
						}
				    }
				}
    		break;
    	}
    }

    fout.close();
    return 0;
}