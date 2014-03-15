/*
ID: anant901
PROG: milk3
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Globals
int cap_a, cap_b, cap_c; 
bool ans[25];
bool visited[25][25][25];

void dfs(int a, int b, int c) {
	//cout<<a<<" "<<b<<" "<<c<<endl;
	if(visited[a][b][c]) return;
	visited[a][b][c]=1;
	if(a==0) ans[c]=1;
	else {
		// a-> b
		if(a<=cap_b-b) dfs(0,b+a,c); else dfs(a-(cap_b-b),cap_b,c);
		// a-> c
		if(a<=cap_c-c) dfs(0,b,c+a); else dfs(a-(cap_c-c),b,cap_c);
	}
	if(b>0) {
		// b-> a
		if(b<=cap_a-a) dfs(a+b,0,c); else dfs(cap_a,b-(cap_a-a),c);
		// b-> c
		if(b<=cap_c-c) dfs(a,0,c+b); else dfs(a,b+c-cap_c,cap_c);
	}
	if(c>0) {
		// c->a
		if(c<=cap_a-a) dfs(c+a,b,0); else dfs(cap_a,b,a+c-cap_a);
		// c->b
		if(c<=cap_b-b) dfs(a,b+c,0); else dfs(a,cap_b,c+b-cap_b);
	}
}

int main() {
    ofstream fout ("milk3.out");
    ifstream fin ("milk3.in");
    
    for(int i=0;i<25;i++) ans[i]=0; 
   	for(int i=0;i<25;i++)
   		for(int j=0;j<25;j++)
   			for(int k=0;k<25;k++)
   				visited[i][j][k]=0;

    fin>>cap_a>>cap_b>>cap_c;
	dfs(0,0,cap_c);
	bool first = 1;
	for(int i=cap_c-cap_b;i<=cap_c;i++) {
		if(ans[i]) {
			if(!first) {
				fout<<" ";
			}
			first = 0;
			fout<<i;
		}
	}
	fout<<endl;
	fout.close();
    return 0;
}