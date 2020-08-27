#include<cstdio>
#include<stack>

using namespace std;

int main() {
  int n,m,x,y;
  int i,j;
  int ansx,ansy;
  scanf("%d %d %d %d",&n,&m,&x,&y);
  ansx = x;
  ansy = y;
  for(i=0;i<n;i++) {
    for(j=0;j<m;j++) {
      printf("%d %d\n",ansx,ansy);
      if(j<(m-1)) ansy++;
      if(ansy>m) ansy=1;
    }
    ansx++;
    if(ansx>n) ansx=1;
  }
  return 0;
}
