/*
ID: anant901
PROG: ariprog
LANG: C++
*/

/*
Using a bool array of 125000 size passed the tests.
A set for bisquares would not.
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ofstream fout ("ariprog.out");
	ifstream fin ("ariprog.in");
    	
	int N,M;
	fin>>N>>M;
	//Length of AP = N
	//0<=i<=M where i is a bisquare term	

	bool bisquares[125005];
	for(int i=0;i<=125004;i++)
		bisquares[i] = 0;
	
	//set <int> bisquares;
	for(int i=0;i<=M;i++) {
		for(int j=0;j<=M;j++)
			//bisquares.insert(i*i+j*j);
			bisquares[i*i+j*j]=1;
	}
	
	int total = 0;
	//Go brute-force
	for (int i=1;i<=2*M*M/(N-1);i++) {
		//i is the AP difference
		for(int j=0;j<=2*M*M-(N-1)*i;j++) {
			//j is the first term of AP
			if (bisquares[j] && (j+(N-1)*i<=M*M*2)) {
				int found = 1;
				for(int k=0;k<N;k++) {
					if (bisquares[j+k*i]==0) {
						found = 0;
						break;
					}
				}
				if (found) {
					total+=1;
					fout<<j<<" "<<i<<endl;
				}
			}
		}
	}
	if(total==0) fout<<"NONE\n";
	fout.close();
	return 0;
}
