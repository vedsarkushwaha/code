#include <cstdio>
#include <vector>
#define limit 15
using namespace std;

vector<int> ind;
int mat[limit+2][limit+2];

void init() {
  int i;
  for(i=1;i<=limit;i++) {
    ind.push_back(i);
  }
}

void printVec() {
  int i;
  for(i=0;i<ind.size();i++) printf("%d ",ind[i]);
}

int getSum() {
  int i,sm=0;
  for(i=1;i<=limit;i++) {
    sm+=mat[i][ind[i-1]];
  }
  return sm;
}

int main() {
  int i,j,tmp,gSum=0,sm;
  init();
  for(i=1;i<=limit;i++) {
    for(j=1;j<=limit;j++) {
      scanf("%d",&tmp);
      mat[i][j]=tmp;
    }
  }
  int flag=0;
  do {
    if(ind[0]!=flag) {
      flag=ind[0];
      printf("%d\n",flag);
    }
    sm=getSum();
    if(gSum<sm) {
      gSum=sm;
      printf("%d\n",gSum);
    }
  } while(next_permutation(ind.begin(),ind.end()));
  printf("%d\n",gSum);
  return 0;
}
