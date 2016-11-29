#include <cstdio>
#include <utility>
#include <cmath>
#include <string>
#include <iostream>
#define L 50

using namespace std;

pair<int,int> getNextPoint(pair<int,int> pnt) {

  if(pnt.first==L && pnt.second==L) {
    return make_pair(-1,-1);
  }
  if(pnt.first==L) {
    return make_pair(0, pnt.second+1);
  }
  else {
    return make_pair(pnt.first+1, pnt.second);
  }
}

bool chkRightTriangle(pair<int,int> a, pair<int,int> b, pair<int,int> c) {
  double d1=sqrt((a.second-b.second)*(a.second-b.second)+(a.first-b.first)*(a.first-b.first));
  double d2=sqrt((b.second-c.second)*(b.second-c.second)+(b.first-c.first)*(b.first-c.first));
  double d3=sqrt((c.second-a.second)*(c.second-a.second)+(c.first-a.first)*(c.first-a.first));
  if(abs(d1*d1-d2*d2-d3*d3)<0.00001 || abs(d2*d2-d1*d1-d3*d3)<0.00001 || abs(d3*d3-d2*d2-d1*d1)<0.00001) {
    return true;
  }
  return false;
}

void print(string str) {
  cout<<str<<endl;
  fflush(stdout);
}

int main() {
  int i,j,k;
  pair<int,int> o;
  pair<int,int> a;
  pair<int,int> b;
  o = make_pair(0,0);
  a = make_pair(0,0);
  b = make_pair(0,0);
  int cnt=0;
  while(1) {
    // print("inside upper while");
    a=getNextPoint(a);
    if(a.first==-1) break;
    if(a.first==L && a.second==L) break;
    printf("%d %d\n",a.first, a.second);
    b=getNextPoint(a);
    while(1) {
      // printf("%d %d\n",b.first, b.second);
      // print("inside lower while");
      if(b.first==-1) {
        break;
      }
      if(chkRightTriangle(o,a,b)) {
        cnt++;
        // printf("%d %d %d %d\n",a.first,a.second,b.first,b.second);
      }
      b=getNextPoint(b);
    }
  }
  printf("%d\n",cnt);
  return 0;
}
