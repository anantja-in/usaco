/*
ID: anant901
PROG: humble
LANG: C++
*/

/*
DP Problem
Need to find only the Nth number, don't need to calculate the rest
Maintain a sorted list of N candidates.
For every prime, mutiply it and all its powers with every number already in the
sequence. If it's less than the largest, kick the largest out and insert the
number. Once done with all the primes, output Nth number

We keep 1 in the arr since it makes it easier, we just output arr[N]

*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
long arr[100005];
long K,N;

int search(int start_index, int end_index, long n) {
  if (start_index>end_index) return -1;
  int mid = (start_index+end_index)/2;
  if(arr[mid]==n) return -1; //Should never happen.
  if(arr[mid]>n) return search(start_index, mid-1, n);
  else return search(mid+1, end_index, n);
}

int insert(long n){
  int
  return 1;
}

int main() {
    ofstream fout ("humble.out");
    ifstream fin ("humble.in");

    arr[0]=1;
    long count = 1;
    fin>>K>>N;
    for (int i=0;i<K;i++) {
      long p; //p is the current prime
      fin>>p;
      for (long i=0;i<count;i++){

      }
    }


    fout.close();
    return 0;
}
