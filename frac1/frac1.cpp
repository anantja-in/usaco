/*
ID: anant901
PROG: frac1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int gcd(int a, int b) {
	if(a<b) return gcd(b,a);
	if (b==0) return a;
	return gcd(b,a%b);
}

int main() {
    ofstream fout ("frac1.out");
    ifstream fin ("frac1.in");
    int N;
    fin>>N;

    int num[26000];
    int denom[26000];
    double frac[26000];

    int tot=0;
    for(int i=1;i<=N;i++)
    	for(int j=0;j<=i;j++) {
    		if(gcd(i,j)==1) {
    			denom[tot]=i;
    			num[tot]=j;
    			tot++;
    		}
    	}

    for(int i=0;i<tot;i++)
    	frac[i]=(double)num[i]/denom[i];

    for(int i=0;i<tot;i++) {
    	for(int j=0;j<tot;j++) {
    		if(frac[i]<frac[j]) {
    			int temp=num[i];
    			num[i]=num[j];
    			num[j]=temp;

    			temp=denom[i];
    			denom[i]=denom[j];
    			denom[j]=temp;

    			double ftemp = frac[i];
    			frac[i]=frac[j];
    			frac[j]=ftemp;
    		}
    	}
    }

    for(int i=0;i<tot;i++) {
    	fout<<num[i]<<"/"<<denom[i]<<endl;
    }

    fout.close();
    return 0;
}