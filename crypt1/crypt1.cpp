/*
ID: anant901
PROG: crypt1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int n;
int arr[9];

int check(int num,int nod)
{
	int c=0;
	while(num>0)
	{
	int a=num%10;
	c++;
	int flag=0;
	for(int x=0;x<n;x++)
		if(a==arr[x]) flag++;
	if(!flag) return 0;
	num-=a;
	num/=10;
	}
	if(c==nod)
		return 1;
	else 
		return 0;
	
}
int main() {
    ofstream fout ("crypt1.out");
    ifstream fin ("crypt1.in");
    
	fin>>n;
	for(int x=0;x<n;x++)
		fin>>arr[x];
	int count=0;
	for(int x=0;x<n;x++)
	{
		for(int y=0;y<n;y++)
		{
			for(int z=0;z<n;z++)
			{
				for(int p=0;p<n;p++)
				{
					for(int q=0;q<n;q++)
					{
						int num1=arr[x]*100 + arr[y]*10 + arr[z];
						int num2=arr[p]*10 + arr[q];
						int flag=0;
						if(check(num1 * arr[q],3)) flag++;
						if(check(num1 * arr[p],3)) flag++;
						if(check(num1 * num2,4)) flag++;
						
						if(flag==3) 
						count++;
						
					}
				}
			}
		}
	}
	fout<<count<<endl;
    return 0;
}