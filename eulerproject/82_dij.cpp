#include <cstdio>
#include <climits>
#define limit 7
#define ll long long
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
  print(arr);
  return 0;
}
