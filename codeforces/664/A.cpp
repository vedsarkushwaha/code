#include<cstdio>

using namespace std;

int main() {
  int T;
  int r,g,b,w;
  int cnt;

  scanf("%d",&T);
  while(T--) {
    scanf("%d %d %d %d",&r,&g,&b,&w);
    cnt = 0;

    if(r%2==0) cnt++;
    if(g%2==0) cnt++;
    if(b%2==0) cnt++;
    if(w%2==0) cnt++;

    if(cnt>=3) printf("Yes\n");
    else if((cnt<=1) && (r>0 && g>0 && b>0))  printf("Yes\n");
    else printf("No\n");
  }
  return 0;
}
