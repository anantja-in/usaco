/*
ID: anant901
PROG: castle
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int w,h, castle[55][55];
bool visited[55][55];
int roomCount;
int maxRoomSize;

int visit(int x, int y) {
    if (!visited[x][y]) {
        visited[x][y]=1;
        int room_size = 1;
        int room_number = castle[x][y];

        if (room_number>=8) {
            room_number-=8;
        }
        else {
            //Check if can go south
            if (x<h-1)
                room_size+=visit(x+1,y);
        }

        if (room_number>=4) {
            room_number-=4;
        }
        else {
            //Check if we can go east
            if (y<w-1)
                room_size += visit(x,y+1);
        }

        if (room_number>=2) {
            room_number-=2;
        }
        else {
            //Check if we can go north
            if (x>0) 
                room_size += visit(x-1,y);
        }

        if (room_number==0) {
            //Check if we can go west
            if (y>0)
                room_size += visit(x,y-1);
        }
        return room_size;
    }
    return 0;
}
int main() {
    ofstream fout ("castle.out");
    ifstream fin ("castle.in");

    // Input
    fin>>w>>h;
    for(int x=0;x<h;x++) for(int y=0;y<w;y++) fin>>castle[x][y];

    // Clear visited
    for(int x=0;x<h;x++) for(int y=0;y<w;y++) visited[x][y]=0;
	
    // Find roomCount and maxRoomSize
    roomCount = 0;
    maxRoomSize = 0;
    for(int x=0;x<h;x++) for(int y=0;y<w;y++) {
        if (!visited[x][y]) {
            int room_size = visit(x,y);
            roomCount+=1;
            if (room_size>maxRoomSize) maxRoomSize=room_size;
        }
    }

    fout<<roomCount<<endl<<maxRoomSize<<endl;
    int maxMergedRoomSize = 0;
    char maxMergedNE;
    int maxMergedX, maxMergedY;

    for(int y=0;y<w;y++) {
        for(int x=h-1;x>=0;x--) {
            // Attempt to remove N
            if (x>0) {
                int room_number = castle[x][y];
                if (room_number>=8) room_number-=8;
                if (room_number>=4) room_number-=4;
                if (room_number>=2) {
                    castle[x][y]-=2;
                    castle[x-1][y]-=8;
                    // Clear visited
                    for(int i=0;i<h;i++) for(int j=0;j<w;j++) visited[i][j]=0;
                    maxRoomSize = 0;
                    for(int i=0;i<h;i++) for(int j=0;j<w;j++) {
                        if (!visited[i][j]) {
                            int room_size = visit(i,j);
                            if (room_size>maxRoomSize) maxRoomSize=room_size;
                        }
                    }
                    if (maxMergedRoomSize<maxRoomSize) {
                        maxMergedRoomSize=maxRoomSize;
                        maxMergedNE = 'N';
                        maxMergedX = x+1;
                        maxMergedY = y+1;
                    }

                    castle[x][y]+=2;
                    castle[x-1][y]+=8;
                }
            }
            
            // Attempt to remove E
            if (y<w-1) {
                int room_number = castle[x][y];
                if (room_number>=8) room_number-=8;
                if (room_number>=4) {
                    castle[x][y]-=4;
                    castle[x][y+1]-=1;
                    // Clear visited
                    for(int i=0;i<h;i++) for(int j=0;j<w;j++) visited[i][j]=0;
                    maxRoomSize = 0;
                    for(int i=0;i<h;i++) for(int j=0;j<w;j++) {
                        if (!visited[i][j]) {
                            int room_size = visit(i,j);
                            if (room_size>maxRoomSize) maxRoomSize=room_size;
                        }
                    }
                    if (maxMergedRoomSize<maxRoomSize) {
                        maxMergedRoomSize=maxRoomSize;
                        maxMergedNE = 'E';
                        maxMergedX = x+1;
                        maxMergedY = y+1;
                    }

                    castle[x][y]+=4;
                    castle[x][y+1]+=1;
                }
            }
        }
    }
    fout<<maxMergedRoomSize<<endl<<maxMergedX<<" "<<maxMergedY<<" "<<maxMergedNE<<endl;

    return 0;
}