/*
ID: anant901
PROG: sprime
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;
ofstream fout ("sprime.out");

bool is_prime(long long n) {
	if(n==1) return 0;
	if(n==2) return 1;
	for(long long i=2; i<=sqrt(n); i++) {
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

void sprime(long long prefix, int digits) {
	for(int i=1; i<=9; i++) {
		long long num = prefix*10+i;
		if(is_prime(num)) {
			if(toStr(num).length()==digits)
				fout<<num<<endl;
			else
				sprime(num, digits);
		}
	}
}

int main() {
    ifstream fin ("sprime.in");
    int N;
    fin>>N;
    sprime(0,N);
    fout.close();
    return 0;
}