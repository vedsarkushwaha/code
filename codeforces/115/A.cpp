#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
  int n;
  int arr[2001];
  int i,tmp;
  scanf("%d",&n);
  for(i=0;i<n;i++) {
    scanf("%d",&tmp);
    arr[i+1]=tmp;
  }
  int res = 1;
  int length=0;
  for(i=1;i<=n;i++) {
    length=0;
    tmp = i;
    while(tmp!=-1) {
      tmp = arr[tmp];
      length++;
    }
    res = max(length, res);
  }
  printf("%d",res);
  return 0;
}
