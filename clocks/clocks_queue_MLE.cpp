/*
ID: anant901
PROG: clocks
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <queue>
#include <string>

using namespace std;

void char_apply(int *a, int character) {
	a[character-'a']+=3;
	a[character-'a']%=12;
}

void digit_apply(int *a, char digit) {
	//Given digit, apply the relevant transform
	switch(digit) {
		case '1':
			char_apply(a, 'a');
			char_apply(a, 'b');
			char_apply(a, 'd');
			char_apply(a, 'e');
			break;
		case '2':
			char_apply(a, 'a');
			char_apply(a, 'b');
			char_apply(a, 'c');
			break;
		case '3':
			char_apply(a, 'b');
			char_apply(a, 'c');
			char_apply(a, 'e');
			char_apply(a, 'f');
			break;
		case '4':
			char_apply(a, 'a');
			char_apply(a, 'd');
			char_apply(a, 'g');
			break;
		case '5':
			char_apply(a, 'b');
			char_apply(a, 'd');
			char_apply(a, 'e');
			char_apply(a, 'f');
			char_apply(a, 'h');
			break;
		case '6':
			char_apply(a, 'c');
			char_apply(a, 'f');
			char_apply(a, 'i');
			break;
		case '7':
			char_apply(a, 'd');
			char_apply(a, 'e');
			char_apply(a, 'g');
			char_apply(a, 'h');
			break;
		case '8':
			char_apply(a, 'g');
			char_apply(a, 'h');
			char_apply(a, 'i');
			break;
		case '9':
			char_apply(a, 'e');
			char_apply(a, 'f');
			char_apply(a, 'h');
			char_apply(a, 'i');
			break;
	}
}

int check(string s, int* clocks) {
	int clocks_temp[9];
	for(int i=0;i<9;i++) clocks_temp[i]=clocks[i];
	for(int i=0; i<s.length(); i++) {
		char a = s[i];
		digit_apply(clocks_temp,a);
	}
	int done = 0;
	for (int i=0; i<9; i++)
		if (clocks_temp[i]!=0) done++;
	if (done>0) return 0; else return 1;
}

int main() {
	ofstream fout ("clocks.out");
    ifstream fin ("clocks.in");
    int clocks[9];
    for(int x=0;x<9;x++) {
    	fin>>clocks[x];
    	clocks[x]%=12;
    }
    queue<string> q;
    int found = 0;
    q.push("");
    while(!found) {
    	string cur = q.front();
    	q.pop();
    	if (check(cur, clocks)) {
    		found = 1;
    		for (int i=0; i<cur.length(); i++) {
    			if(i!=cur.length()-1)
    				fout<<cur[i]<<" ";
    			else
    				fout<<cur[i];
    		}
    	}
    	else {
    		for(int i=1;i<=9;i++) {
		    	string s = cur;
		    	s+=char('0'+i);
		    	q.push(s);
		    }
    	}
    }
    fout<<endl;
    fout.close();
}