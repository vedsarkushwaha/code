#include <cstdio>
#include <set>
#include <cmath>
#include <iostream>
using namespace std;

set<int> st;

bool chkSqr(int i) {
  int d = sqrt(i);
  if(d*d == i) {
    cout<<d<<" "<<d*d<<" "<<i<<endl;
    return true;
  }
  else return false;
}

int main() {
  int i=2,k=1,N,j;

  scanf("%d",&N);

  while(i<=N) {
    printf("i=%d\n",i);
    for(j=2;j<=N;j++) {
      st.insert(k*j);
    }
    k++;
    i=i<<1;
  }
  printf("%d\n",st.size());

  // int nonSqr=N-1;
  //
  // for(i=2;i<=N;i++) {
  //   if(chkSqr(i)) {
  //     printf("%d is square\n",i);
  //     N--;
  //   }
  // }

  set<int> power;

  for(i=2;i<=N;i++) {
    for(j=2;j<=N;j++) {
      int d = pow(i,j);
      if(d>N) break;
      else power.insert(d);
    }
  }

  printf("Non Power: %d\n",N-1-power.size());
  printf("Unique values:%d\n",N*st.size());
  return 0;
}
