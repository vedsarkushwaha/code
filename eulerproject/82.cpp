#include <cstdio>
#include <algorithm>
#include <climits>

#define ll long long
#define limit 82

using namespace std;

void print(ll arr[limit][limit]) {
  int i,j;
  for(i=1;i<=limit-2;i++) {
    for(j=1;j<=limit-2;j++) {
      printf("%lld ",arr[i][j]);
    }
    printf("\n");
  }
}

int main() {
  ll arr[limit][limit]={0};
  ll rd[limit][limit]={0};
  ll ru[limit][limit];
  ll i,j,k;
  ll tmp;
  char ch;
  for(i=0;i<=limit-1;i++) {
    for(j=0;j<=limit-1;j++) {
      if(i==0 || j==0 || i==limit-1 || j==limit-1) {
        arr[i][j]=INT_MAX;
        rd[i][j]=INT_MAX;
        ru[i][j]=INT_MAX;
      }
      else {
        scanf("%lld",&tmp);
        scanf("%c",&ch);
        arr[i][j]=tmp;
      }
    }
  }

  for(i=1;i<=limit-2;i++) {
    for(j=1;j<=limit-2;j++) {
      if(j==1) rd[i][j]=arr[i][j];
      else rd[i][j]=arr[i][j]+min(rd[i-1][j], rd[i][j-1]);
    }
  }

  for(i=limit-2;i>=1;i--) {
    for(j=1;j<=limit-2;j++) {
      if(j==1) ru[i][j] = arr[i][j];
      else ru[i][j]=min(rd[i][j], arr[i][j]+min(ru[i+1][j], ru[i][j-1]));
    }
  }

  // for(i=1;i<=limit-2;i++) {
  //   for(j=1;j<=limit-2;j++) {
  //     arr[i][j]=min(ru[i][j], rd[i][j]);
  //   }
  // }

  // print(arr);
  tmp=ru[limit-2][limit-2];
  for(i=0;i<limit-2;i++) {
    tmp = min(tmp, ru[i][limit-2]);
  }
  printf("%lld\n",tmp);
  return 0;
}
