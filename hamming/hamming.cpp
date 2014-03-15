/*
ID: anant901
PROG: hamming
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;
ofstream fout ("hamming.out");
ifstream fin ("hamming.in");
int stop = 0;

int hd(int a, int b) {
	bool A2[10], B2[10];
	for(int x=0;x<10;x++) {
		A2[x]=0; B2[x]=0;
	}
	int lA=0;
	while(a!=0) {
		A2[lA++]=a%2;
		a/=2;
	}
	int lB=0;
	while (b!=0) {
		B2[lB++]=b%2;
		b/=2;
	}
	int l = (lA>lB)?lA:lB;
	int hd=0;
	for(int x=0;x<l;x++) {
		if (A2[x]!=B2[x]) hd++;
	}
	return hd;
}

void generate(int start, int N, int max, int D, int sequence[], int sequence_length) {
	if (stop) return;
	if (N==0) {
		// Print the sequence
		int count=0;
		for(int x=0;x<sequence_length; x++, count++) {
			if (count==10) {
				fout<<endl;
				count=0;
			}
			if (count==0)
				fout<<sequence[x];
			else 
				fout<<" "<<sequence[x];
		}
		fout<<endl;
		stop = 1;
		return;
	}
	if (start==max) return;

	//Check if start is compatible with current sequence:
	int compatible = 1;
	for(int x=0;x<sequence_length;x++) {
		if(hd(sequence[x], start)<D)
			compatible=0;
	}
	if (compatible==0) {
		generate(start+1, N, max, D, sequence, sequence_length);
	} 
	else {
		int sequence_new[256];
		for(int x=0;x<sequence_length;x++) {
			sequence_new[x]=sequence[x];
		}
		sequence_new[sequence_length]=start;
		generate(start+1, N-1, max, D, sequence_new, sequence_length+1);
		generate(start+1, N, max, D, sequence, sequence_length);
	}

}

int main() {
    int N,B,D;
    fin>>N>>B>>D;
   	generate(0, N, pow(2,B), D, 0, 0);
    fout.close();
    return 0;
}