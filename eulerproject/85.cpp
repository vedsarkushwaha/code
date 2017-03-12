#include <cstdio>
#include <climits>
#include <cstdlib>

#define limit 2000000

using namespace std;

int main() {
  int i,j,k,l,diff=INT_MAX;
  int ansi,ansj,sm;
  for(i=1;i<=2000;i++) {
    for(j=1;j<=2000;j++) {
      sm=0;
      for(k=1;k<=i;k++) {
        for(l=1;l<=j;l++) {
          sm+=((i-k+1)*(j-l+1));
        }
      }
      if(abs(sm-limit)<diff) {
        diff=abs(sm-limit);
        ansi=i;
        ansj=j;
        printf("%d %d %d\n",ansi,ansj,sm);
      }
      if(sm>limit) break;
    }
  }
  return 0;
}
