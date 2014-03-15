/*
ID: anant901
PROG: lamps
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int N, C; //Lamp# and counter#
int total_ways = 0;
ofstream fout ("lamps.out");
ifstream fin ("lamps.in");

bool reachable(bool state[]) {
	for(int s1=0;s1<2;s1++) 
    	for(int s2=0;s2<2;s2++) 
    		for(int s3=0;s3<2;s3++) 
    			for(int s4=0;s4<2;s4++) {
    				int moves = s1+s2+s3+s4;
    				if (moves==C || (moves+2)<=C) {
    					bool arr[6];
    					for(int x=0;x<6;x++) arr[x]=1;
    					if(s1)
    						for(int x=0;x<6;x++) 
    							arr[x] = (arr[x])?0:1;
    					if(s2)
    						for(int x=0;x<6;x++) 
    							if(x%2==0) 
    								arr[x]= (arr[x])?0:1;
    					if(s3)
    						for(int x=0;x<6;x++)
    							if(x%2==1)
    								arr[x]= (arr[x])?0:1;
    					if(s4)
    						for(int x=0;x<6;x++)
    							if(x%3==0)
    								arr[x]= (arr[x])?0:1;
    					bool reachable = 1;
    					for(int x=0;x<6;x++)
    						if(state[x]!=arr[x])
    							reachable = 0;
    					if (reachable) {
    						return 1;
    					}
    				}
    			}
    return 0;
}
void f(int target[], int pos, bool arr[]) {
	if(pos<6) {
		if(target[pos]==2) {
			arr[pos] = 0;
			f(target, pos+1, arr);
			arr[pos] = 1;
			f(target, pos+1, arr);
		}
		else {
			arr[pos] = target[pos];
			f(target, pos+1, arr);
		}
	}
	else {
		// pos is 6
		//cout<<"Checking: ";
		//for(int x=0;x<6;x++) cout<<arr[x];
		//cout<<" Answer: "<<reachable(arr);
		//cout<<endl;
		if(reachable(arr)) {
			for(int x=0;x<N;x++)
				fout<<arr[x%6];
			fout<<endl;
			total_ways++;
		}
	}
	return;
}

int main() {
    fin>>N>>C;
    int on[110], off[110];
    for(int x=0;x<N;x++) {
    	on[x]=0; off[x]=0;
   	}

    int i = 0;
    int j;
    bool stop = 0;
    do {
    	fin>>j;
    	if (j!=-1)
    		on[j-1]=1;
    	else
    		stop=1;
    } while(!stop);
    i=0;
    stop=0;

    do {
    	fin>>j;
    	if(j!=-1)
    		off[j-1]=1;
    	else
    		stop=1;
    } while(!stop);

    int target[110];
    for(int x=0;x<N;x++) {
    	if(on[x])
    		target[x]=1;
    	else if(off[x])
    		target[x]=0;
    	else
    		target[x]=2;
    }
    for(int i=0;i<6;i++) {
    	//Check if impossible
    	int pos=2;
    	for(int x=i;x<N;x+=6) {
    		if(on[x]) {
    			if(pos==2) {
    				pos=1;
    			}
    			else if (pos==0) {
    				fout<<"IMPOSSIBLE"<<endl;
    				return 0;
    			}
    		}
    		if(off[x]) {
    			if(pos==2) {
    				pos=0;
    			}
    			else if (pos==1) {
    				fout<<"IMPOSSIBLE"<<endl;
    				return 0;
    			}
    		}
    	}

    	//Make it consistent
    	if(pos!=2) {
    		for(int x=i; x<N; x+=6) {
    			target[x]=pos;
    		}
    	}
    }

    //Now generate for first 6 at 2's position
    bool worker[6];
    for(int x=0;x<6;x++) worker[x]=0;
    f(target, 0, worker);
	if(total_ways==0) fout<<"IMPOSSIBLE"<<endl;
    fout.close();
    return 0;
}