#include <cstdio>
#include <algorithm>
#include <climits>

#define ll long long

using namespace std;

int main() {
  ll arr[82][82];
  ll rd[82][82]={0};
  ll ru[82][82]={0};
  ll i,j,k;
  ll tmp;
  char ch;
  for(i=0;i<=6;i++) {
    for(j=0;j<=6;j++) {
      if(i==0 || j==0 || i==6 || j==6) arr[i][j]=INT_MAX;
      else {
        scanf("%lld",&tmp);
        scanf("%c",&ch);
        arr[i][j]=tmp;
      }
    }
  }

  for(i=1;i<6;i++) {
    for(j=1;j<6;j++) {
      if(i==1) rd[i][j]=arr[i][j];
      else rd[i][j]=arr[i][j]+min(arr[i-1][j], arr[i][j-1]);
    }
  }

  for(i=5;i>0;i--) {
    for(j=1;j<6;j++) {
      if(i==1) ru[i][j] = arr[i][j];
      else ru[i][j]=arr[i][j]+min(arr[i+1][j], arr[i][j-1]);
    }
  }

  printf("%lld\n",arr[5][5]);
  return 0;
}
