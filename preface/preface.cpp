/*
ID: anant901
PROG: preface
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
long result[7];

// I V X L C D M
// 0 1 2 3 4 5 6

void f(int n) {
	//cout<<n<<" called"<<endl;
	if (n>=1000) {
		result[6]+=(n/1000);
		n%=1000;
	}
	if (n>=900) {
		result[6]++; result[4]++;
		n-=900;
	}
	if (n>=500) {
		result[5]++;
		n-=500;
	}
	if (n>=400) {
		result[5]++; result[4]++;
		n-=400;
	}
	if (n>=100) {
		result[4]+=(n/100);
		n%=100;
	}
	if (n>=90) {
		result[4]++; result[2]++;
		n-=90;
	}
	if (n>=50) {
		result[3]++;
		n-=50;
	}
	if (n>=40) {
		result[2]++; result[3]++;
		n-=40;
	}
	if (n>=10) {
		result[2]+=(n/10);
		n%=10;
	}
	if (n==9) {
		result[0]++; result[2]++;
		n=0;
	}
	if (n>=5) {
		result[1]++;
		n-=5;
	}
	if (n==4) {
		result[0]++; result[1]++;
		n=0;
	}
	result[0]+=n;
	/*
	cout<<"Array state:"<<endl;
	for(int x=0;x<7;x++) cout<<result[x]<<" ";
	cout<<endl<<endl;
	*/
	return;
}

int main() {
    ofstream fout ("preface.out");
    ifstream fin ("preface.in");
    int N;
    fin>>N;
    for(int x=0;x<7;x++) result[x]=0;

    for(int x=1;x<=N;x++)
    	f(x);
    
    int print_till=0;
    
    for(int x=6;x>=0;x--) 
    	if (result[x]!=0) {
    		print_till = x;
    		break;
    	}
    for(int x=0;x<=print_till;x++) {
    	switch(x) {
    		case 0: fout<<"I "; break;
    		case 1: fout<<"V "; break;
    		case 2: fout<<"X "; break;
    		case 3: fout<<"L "; break;
    		case 4: fout<<"C "; break;
    		case 5: fout<<"D "; break;
    		case 6: fout<<"M "; break;
    	}
    	fout<<result[x]<<endl;
    }

    fout.close();
    return 0;
}