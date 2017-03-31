#include <cstdio>
#define limit 300
using namespace std;

int arr[limit+1][limit+1][limit+1];

void init() {
  int i,j;
  arr[0][0][0]=2;
  arr[1][1][0]=2;
  arr[1][0][1]=2;
  arr[0][1][1]=2;
  // arr[1][2][3]=2;
  for(i=1;i<limit+1;i++) {
    arr[0][0][i]=2;
    arr[0][i][0]=2;
    arr[i][0][0]=2;
    for(j=1;j<limit+1;j++) {
      arr[i][j][j]=1;
      arr[j][i][j]=1;
      arr[j][j][i]=1;
      if(i==j) {
        arr[i][i][0]=2;
        arr[i][0][i]=2;
        arr[0][i][i]=2;
      }
      else {
        arr[i][j][0]=1;
        arr[j][i][0]=1;
        arr[i][0][j]=1;
        arr[j][0][i]=1;
        arr[0][i][j]=1;
        arr[0][j][i]=1;
      }
    }
  }
}

void print() {
  int i,j,k;
  for(i=0;i<limit+1;i++) {
    for(j=0;j<limit+1;j++) {
      for(k=0;k<limit+1;k++) {
        printf("%d %d %d:%d\n",i,j,k,arr[i][j][k]);
      }
    }
  }
}

void printAns() {
  int i;
  for(i=1;3*i<=limit;i++) {
    printf("%d %d %d : %d\n",i,2*i,3*i,arr[i][2*i][3*i]);
  }
}

int main() {
  int i,j,k,l;
  init();
  for(i=1;i<limit+1;i++) {
    for(j=1;j<limit+1;j++) {
      for(k=1;k<limit+1;k++) {
        // look back i
        l=i-1;
        while(l>=0) {
          if(arr[l][j][k]==2) {
            // if(i==3 && j==6 && k==9) printf("-%d %d %d-",l,j,k);
            arr[i][j][k]=1;
            break;
          }
          l--;
        }
        // look back j
        l=j-1;
        while(l>=0) {
          if(arr[i][l][k]==2) {
            // if(i==3 && j==6 && k==9) printf("*%d %d %d-",i,l,k);
            arr[i][j][k]=1;
            break;
          }
          l--;
        }
        // look back k
        l=k-1;
        while(l>=0) {
          if(arr[i][j][l]==2) {
            // if(i==3 && j==6 && k==9) printf("+%d %d %d-",i,j,l);
            arr[i][j][k]=1;
            break;
          }
          l--;
        }
        if(arr[i][j][k]==0) {
          arr[i][j][k]=2;
        }
      }
    }
  }
  // print();
  printAns();
  return 0;
}
