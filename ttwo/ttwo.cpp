/*
ID: anant901
PROG: ttwo
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int return_next_x(int current_x, int direction) {
	switch(direction) {
		case 0:
			return current_x-1;
		case 1:
			return current_x;
		case 2:
			return current_x+1;
		case 3:
			return current_x;
	}
	cout<<"Error in return_next_x";
	return -1;
}

int return_next_y(int current_y, int direction) {
	switch(direction) {
		case 0:
			return current_y;
		case 1:
			return current_y+1;
		case 2:
			return current_y;
		case 3:
			return current_y-1;
	}
	cout<<"Error in return_next_y";
	return -1;
}

int main() {
    ofstream fout ("ttwo.out");
    ifstream fin ("ttwo.in");

    char state[11][11];
    int farmer_initial_x, farmer_initial_y;
    int cow_initial_x, cow_initial_y;
    for(int i=0;i<10;i++) 
    	for(int j=0;j<10;j++) {
    		fin>>state[i][j];
    		if(state[i][j]=='C') {
    			cow_initial_x=i;
    			cow_initial_y=j;
    		}
    		if(state[i][j]=='F') {
    			farmer_initial_x=i;
    			farmer_initial_y=j;
    		}
    	}

    int farmer_current_x = farmer_initial_x;
    int farmer_current_y = farmer_initial_y;
    int cow_current_x = cow_initial_x;
    int cow_current_y = cow_initial_y;

    bool solved = 0;
    long TIME = 0;
    int farmer_direction = 0;
    int cow_direction = 0;

    while(!solved) {
    	//Make the farmer move
    	bool turn = 0;
    	int fnx = return_next_x(farmer_current_x, farmer_direction);
    	int fny = return_next_y(farmer_current_y, farmer_direction);
    	if (fnx<0 || fnx>9 || fny<0 || fny>9 || state[fnx][fny]=='*')
    		turn = 1;

    	if (turn) {
    		farmer_direction+=1;
    		farmer_direction%=4;
    	}
    	else {
    		farmer_current_x = fnx;
    		farmer_current_y = fny;
    	}

    	//Make the cow move
    	turn = 0;
    	int cnx = return_next_x(cow_current_x, cow_direction);
    	int cny = return_next_y(cow_current_y, cow_direction);
    	if (cnx<0 || cnx>9 || cny<0 || cny>9 || state[cnx][cny]=='*')
    		turn = 1;
    	if(turn) {
    		cow_direction += 1;
    		cow_direction %= 4;
    	}
    	else {
    		cow_current_x = cnx;
    		cow_current_y = cny;
    	}

    	//cout<<cow_current_x<<' '<<cow_current_y<<endl;
    	//cout<<farmer_current_x<<' '<<farmer_current_y<<endl<<endl;;

    	//Increment time
    	TIME++;

    	//Check if it's solved
    	if (cow_current_x==farmer_current_x && cow_current_y==farmer_current_y)
    		solved=1;

    	// If they're going to meet, they're going to meet in 
        // fewer than 160,000 steps (100*4*100*4)
    	if (TIME>160000) {
    		solved=1;
    		TIME=0;
    	}
    }

    fout<<TIME<<endl;
    fout.close();
    return 0;
}