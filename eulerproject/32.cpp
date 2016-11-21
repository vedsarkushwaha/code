#include <cstdio>
#include <set>
#include <cmath>
#include <iostream>
#include <vector>
#include <set>
#include <cassert>

using namespace std;

bool chkPandigi(int p, int q, int r) {
  int arr[10]={0};
  int tmp;

  int i=p;
  while(i!=0) {
    tmp = i%10;
    i=i/10;
    if(arr[tmp]) {
      return 0;
    }
    else {
      arr[tmp]=1;
    }
  }

  int j=q;
  while(j!=0) {
    tmp = j%10;
    j=j/10;
    if(arr[tmp]) {
      return 0;
    }
    else {
      arr[tmp]=1;
    }
  }

  int k=r;
  while(k!=0) {
    tmp = k%10;
    k=k/10;
    if(arr[tmp]) {
      return 0;
    }
    else {
      arr[tmp]=1;
    }
  }

  if(arr[0]==1) return 0;

  for(i=1;i<10;i++) {
    if(arr[i]==0) return 0;
  }
  return 1;
}

int main() {
  int i,j,k;
  set<int> st;
  for(i=1;i<=10000;i++) {
    for(j=i+1;j<=10000;j++) {
      k = i*j;
      if(chkPandigi(i,j,k)) {
        printf("%d %d %d\n",i,j,k);
        st.insert(k);
      }
    }
  }
  set<int>::iterator it;
  it=st.begin();
  int tmp=0;
  while(it!=st.end()) {
    tmp+=(*it);
    it++;
  }
  printf("%d\n",tmp);
  return 0;
}
