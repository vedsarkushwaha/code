#include <iostream>
#include <vector>
using namespace std;

// Find Kth element without recusion
int findKMedian(vector<int> A,int K) {
  int l,m;
  l=0;
  m=A.size()-1;
  while (l<m) {
    int x=A[K];
    int i=l;
    int j=m;
    do {
      while (A[i]<x) i++;
      while (x<A[j]) j--;
      if (i<=j) {
        int t = A[i]; A[i]= A[j]; A[j] = t; // Swap A[i] & A[j]
        i++; j--;
      }
    } while (i<=j);
    if (j<K) l=i;
    if (K<i) m=j;
  }
  return A[K];
}

int main() {
  int myints[5] = {6,6,6,9,9};
  vector<int> A (myints, myints + sizeof(myints) / sizeof(int) );

  cout << findKMedian(A,2) << endl;
}
