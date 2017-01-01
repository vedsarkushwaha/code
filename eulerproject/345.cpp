#include <cstdio>
#include <vector>
#define limit 5
using namespace std;

vector<int> ind;

void init() {
  int i;
  for(i=1;i<=limit;i++) {
    ind.push_back(1);
  }
}

bool chkValid() {
  int arr[limit+1]={0};
  int i;
  for(i=0;i<ind.size();i++) {
    arr[ind[i]]++;
    if(arr[ind[i]]>1) return false;
  }
  return true;
}

bool nextind() {
  int i,j;
  int last = ind.size()-1;
  if(ind[last]<limit) ind[last]++;
  else {
    while(ind[last]==limit) {
      ind[last]=1;
      last--;
    }
    if(last==-1) return false;
    ind[last]++;
  }
  return true;
}

void printVec() {
  int i;
  for(i=0;i<ind.size();i++) printf("%d ",ind[i]);
  printf("\n");
}

int main() {
  int i,j,tmp;
  int mat[7][7]={0};
  init();
  for(i=1;i<=5;i++) {
    for(j=1;j<=5;j++) {
      scanf("%d",&tmp);
      mat[i][j]=tmp;
    }
  }
  // for(i=1;i<=5;i++) {
  //   for(j=1;j<=5;j++) {
  //     printf("%d ",mat[i][j]);
  //   }
  //   printf("\n");
  // }
  do {
    if(chkValid()) printVec();
  } while(nextind());
  return 0;
}
