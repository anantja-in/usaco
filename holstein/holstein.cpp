/*
ID: anant901
PROG: holstein
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#define types_MAX 30
#define feeds_MAX 20
using namespace std;
ofstream fout ("holstein.out");
ifstream fin ("holstein.in");
int stop = 0;

void generate(int types_count, int feeds_count, int types[], int feeds[][types_MAX], int ones, int sequence[], int sequence_length) {
	/*
	cout<< types_count<<" "<< feeds_count << " "<< ones<<" "<<sequence_length<<endl;
	for(int x=0;x<types_count;x++) cout<<types[x]<<" ";
	cout<<endl;
	for(int x=0;x<types_count;x++) cout<<feeds[0][x]<<" ";
	cout<<endl;
	*/
	if (stop) return;
	if (ones==0) {
		//cout<<"Ones are 0"<<endl;
		return;
	}
	else if (feeds_count==0) {
		//cout<<"Feeds are 0"<<endl;
		return;
	}
	else {
		// Check for 1 at lowest index place
		int remaining[types_MAX];
		for (int x=0;x<types_count;x++) {
			remaining[x] = types[x]-feeds[0][x];
		}

		// Check if satisfied
		int satisfied = 1;
		for (int x=0;x<types_count; x++) {
			if (remaining[x]>0)
				satisfied = 0;
		}
		if (satisfied==1) {
			//cout<<"Done"<<endl;
			/*
			for(int x=0;x<types_count;x++)
				cout<<remaining[x]<<" ";
			cout<<endl;
			for(int x=0;x<sequence_length;x++) 
				cout<<sequence[x]<<" ";
			cout<<endl;
			*/
			sequence_length+=1;
			sequence[sequence_length-1]=1;
			int total = 0;
			for(int x=0;x<sequence_length;x++)
				if (sequence[x]==1)
					total+=1;
			fout<<total;
			for(int x=0;x<sequence_length;x++)
				if (sequence[x]==1)
					fout<<" "<<x+1;
			fout<<endl;
			stop=1;
			return;
		}

		// Remove the feed at lowest index number
		int types_1[types_MAX];
		int types_0[types_MAX];
		for (int x=0;x<types_count;x++) {
			types_1[x] = types[x]-feeds[0][x];
			types_0[x] = types[x];
		}
		int feeds_new[feeds_MAX][types_MAX];
		for(int x=0;x<feeds_count-1;x++) {
			for(int y=0;y<types_count;y++) {
				feeds_new[x][y]=feeds[x+1][y];
			}
		}
		int sequence_1[feeds_MAX];
		int sequence_0[feeds_MAX];
		for(int x=0;x<sequence_length;x++) {
			sequence_1[x]= sequence[x];
			sequence_0[x]= sequence[x];
		}
		sequence_1[sequence_length]=1;
		sequence_0[sequence_length]=0;
		generate(types_count, feeds_count-1, types_1, feeds_new, ones-1, sequence_1, sequence_length+1);
		generate(types_count, feeds_count-1, types_0, feeds_new, ones, sequence_0, sequence_length+1);
	}
}

int main() {
    int types_count, feeds_count, types[types_MAX], feeds[feeds_MAX][types_MAX];
    
    fin>>types_count;
    for (int x=0;x<types_count;x++) fin>>types[x];

    fin>> feeds_count;
	for(int x=0;x<feeds_count;x++)
		for(int y=0; y<types_count;y++)
			fin>>feeds[x][y];

	int sequence[feeds_MAX];
	for (int x=1; x<=feeds_count;x++) {
		//cout<<"x is "<<x<<endl;
		generate(types_count, feeds_count, types, feeds, x, sequence, 0);
    }
    fout.close();
    return 0;
}