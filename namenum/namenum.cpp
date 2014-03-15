/*
ID: anant901
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
int start[24];



using namespace std;
int compare(char arr[13], char input[13], int len)
{
		int x=0; int flag=0;
		
		for(x=0;x<len && (!flag);x++)
		{
		if(input[x]=='2' && (arr[x]!='A' && arr[x]!='B' && arr[x]!='C')) flag++;
		else if (input[x]=='3' && (arr[x]!='D' && arr[x]!='E' && arr[x]!='F')) flag++;
		else if (input[x]=='4' && (arr[x]!='G' && arr[x]!='H' && arr[x]!='I')) flag++;
		else if (input[x]=='5' && (arr[x]!='J' && arr[x]!='K' && arr[x]!='L')) flag++;
		else if (input[x]=='6' && (arr[x]!='M' && arr[x]!='N' && arr[x]!='O')) flag++;
		else if (input[x]=='7' && (arr[x]!='P' && arr[x]!='R' && arr[x]!='S')) flag++;
		else if (input[x]=='8' && (arr[x]!='T' && arr[x]!='U' && arr[x]!='V')) flag++;
		else if (input[x]=='9' && (arr[x]!='W' && arr[x]!='X' && arr[x]!='Y')) flag++;
		}
		return !(flag);
}
int main() {
    ofstream fout ("namenum.out");
    ifstream fin ("namenum.in");
	ifstream findict ("dict.txt");
	
	start[0]=0;
start[1]=363;
start[2]=599;
start[3]=930;
start[4]=1183;
start[5]=1369;
start[6]=1496;
start[7]=1683;
start[8]=1835;
start[9]=1917;
start[10]=2110;
start[11]=2373;
start[12]=2669;
start[13]=3085;
start[14]=3241;
start[15]=3354;
start[16]=3523;
start[17]=3730;
start[18]=4024;
start[19]=4266;
start[20]=4302;
start[21]=4380;
start[22]=4450;
start[23]=4465;

    char input[13];
	fin>>input;
	
	int len = strlen(input);
	int  count=0;
	
	int st=start[(input[0]-50)*3];
	int end=start[(input[0]-49)*3];
	
	int x=0;
	
	while(x<end && x<=4617)
	{
		
		char arr[13];
		findict>>arr;
		if(x>=st)
		{
		if(strlen(arr)==len)
			if(compare(arr,input,len))
			{	fout<<arr<<endl; count++; }
		}
		x++;
	}
	if(!count) fout<<"NONE"<<endl; 
				
    return 0;
}
