/*
ID: anant901
PROG: milk
LANG: C++
*/
#include<fstream>
using namespace std;

int main()
{
	ofstream fout ("milk.out");
    ifstream fin ("milk.in");
	long tot;
	int n;
	int arr[5000][2];
	fin>>tot>>n;
	for(int x=0;x<n;x++)
		fin>>arr[x][0]>>arr[x][1];
	for(int x=1;x<n;x++)
	{
		for(int y=0;y<x;y++)
		{
			if(arr[x][0]<arr[y][0])
			{
				int a,b;
				a=arr[x][0];
				b=arr[x][1];
				arr[x][0]=arr[y][0];
				arr[x][1]=arr[y][1];
				arr[y][0]=a;
				arr[y][1]=b;
			}
		}
	}
	
	long price=0;
	int x=0;
	while(tot>0)
	{
		if(arr[x][1]>=tot)
		{
			
			price+=tot*arr[x][0];
			tot=0;
		}
		else
		{
			tot-=arr[x][1];
			price+=arr[x][1]*arr[x][0];
		}
		x++;
	}
	fout<<price<<endl;	
	
	return 0;
}