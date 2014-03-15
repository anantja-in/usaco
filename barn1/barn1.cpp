/*
ID: anant901
PROG: barn1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("barn1.out");
    ifstream fin ("barn1.in");
    
	int m,s,c;
	
	fin>>m>>s>>c;
	
	int arrcow[200];
	for(int x=0;x<s;x++) arrcow[x]=0;
	for(int x=0;x<c;x++)
	{
		int a;
		fin>>a;
		arrcow[a-1]=1;
	}
	int arrgate[200];
	for(int x=0;x<s;x++) arrgate[x]=0;
	
	int f=0;
	for(int x=0;x<s;x++) 
	{	
		if(!f) 
		{ if(arrcow[x]) 
			{f++;arrgate[x]=1;}
		}
		else
			arrgate[x]=1;
	}
	

	f=0;
	for(int x=s-1;!f;x--)
	{
		if(arrcow[x])
			f++;
		else
			arrgate[x]=0;
	}
	
	
	for(int x=1;x<m;x++)
	{
			int maxstart, maxlen=0;
			int status=0;
			int curlen=0, curstart;
			for(int y=0;y<s;y++)
			{
				if(arrgate[y] && !arrcow[y])
				{
					if(status)
						curlen++;
					else
					{
						curstart=y;
						curlen=1;
						status=1;
					}
				}
				else if(arrgate[y] && arrcow[y])
				{
					if(status)
					{
						if(curlen>maxlen)
						{
							maxlen=curlen;
							maxstart=curstart;
						}
						status=0;
					}
				}
			}
			
			
			for(int y=maxstart;y<maxlen+maxstart;y++)
				arrgate[y]=0;
				
			
			
		
	}
	int ans=0;
	for(int x=0;x<s;x++)
		if(arrgate[x]){ ans++;/*cout<<ans<<":"<<x<<endl;*/}
	
	fout<<ans<<endl;
	
    return 0;
}