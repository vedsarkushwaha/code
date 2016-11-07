#include <cstdio>
#include <algorithm>
#include <climits>

#define ll long long

using namespace std;

int main() {
  ll arr[82][82];
  ll i,j,k;
  ll tmp;
  char ch;
  for(i=0;i<81;i++) {
    for(j=0;j<81;j++) {
      if(i==0 || j==0) arr[i][j]=INT_MAX;
      else {
        scanf("%lld",&tmp);
        scanf("%c",&ch);
        arr[i][j]=tmp;
      }
    }
  }

  for(i=1;i<81;i++) {
    for(j=1;j<81;j++) {
      if(i==1 && j==1) continue;
      arr[i][j]+=min(arr[i-1][j], arr[i][j-1]);
    }
  }

  // for(i=1;i<81;i++) {
  //   for(j=1;j<81;j++) {
  //     printf("%lld ",arr[i][j]);
  //   }
  //   printf("\n");
  // }

  printf("%lld\n",arr[80][80]);
  return 0;
}
