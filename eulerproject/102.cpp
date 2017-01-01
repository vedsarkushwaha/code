#include <cstdio>
#include <cmath>
using namespace std;

double area(int x1,int x2, int x3, int y1, int y2, int y3) {
  return abs((x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2))/2.0);
}

int main() {
  int x1,x2,x3,y1,y2,y3;
  int i,cnt=0;
  double a,a1,a2,a3;
  for(i=0;i<1000;i++) {
    scanf("%d,%d,%d,%d,%d,%d\n",&x1,&y1,&x2,&y2,&x3,&y3);
    a = area(x1,x2,x3,y1,y2,y3);
    a1 = area(x1,x2,0,y1,y2,0);
    a2 = area(x2,x3,0,y2,y3,0);
    a3 = area(x3,x1,0,y3,y1,0);
    // printf("%d %d %d %d %d %d %lf %lf %lf %lf\n",x1,y1,x2,y2,x3,y3,a,a1,a2,a3);
    if(a1+a2+a3-a<0.5) cnt++;
  }
  printf("%d\n", cnt);
  return 0;
}
