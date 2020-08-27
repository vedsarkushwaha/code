#include<cstdio>
#include<vector>

using namespace std;

int main() {
  int n,m,i,j,A,Amax,tmp;
  int foundb;
  Amax = (1<<9);

  vector<int> a,b;

  scanf("%d %d",&n,&m);
  for(i=0;i<n;i++) {
    scanf("%d",&tmp);
    a.push_back(tmp);
  }

  for(i=0;i<m;i++) {
    scanf("%d",&tmp);
    b.push_back(tmp);
  }

  for(A=0;A<Amax;A++) {
    // does there exist ci = ai & bj such that ci|A = A
    for(i=0;i<a.size();i++) {
      foundb = 0;
      for(j=0;j<b.size();j++) {
        tmp = a[i] & b[j];
        if((A | tmp) == A) {
          foundb = 1;
          break;
        }
      }
      if(foundb==0) break;
    }
    if(foundb==1) {
      printf("%d",A);
      break;
    }
  }
  return 0;
}
