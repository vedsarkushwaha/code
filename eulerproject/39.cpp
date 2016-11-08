#include <cstdio>

using namespace std;

int main() {
  int p,b,h,P=1000,i;
  int localSol=0, globalSol=0, ans=0;
  for(i=3;i<=P;i++) {
    localSol=0;
    for(p=1;p<i;p++) {
      for(b=1;b<p;b++) {
        h = i-p-b;
        if(p*p + b*b == h*h) {
          localSol++;
          // printf("%d %d %d\n",p,b,h);
        }
      }
    }
    if(localSol>globalSol) {
      globalSol = localSol;
      ans = i;
    }
  }
  printf("%d\n",ans);
  return 0;
}
