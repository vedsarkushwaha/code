#include <cstdio>
#include <cassert>
using namespace std;

bool chkInc(int num) {
  int tmp=num%10;
  num=num/10;
  while(num) {
    if((num%10)<=tmp) {
      tmp=num%10;
      num/=10;
    }
    else return false;
  }
  return true;
}

bool chkDec(int num) {
  int tmp=num%10;
  num=num/10;
  while(num) {
    if((num%10)>=tmp) {
      tmp=num%10;
      num/=10;
    }
    else return false;
  }
  return true;
}

bool chkBouncy(int num) {
  return !chkInc(num)&&!chkDec(num);
}

int main() {
  int i;
  int cnt=0;
  double limit = 0.99;
  for(i=1;i<=100;i++) {
    if(chkBouncy(i)) cnt++;
  }
  assert(cnt==0);
  for(;i<=10000000;i++) {
    if(chkBouncy(i)) cnt++;
    if(limit*i<=cnt) break;
  }
  printf("%d %d\n",i,cnt);
  return 0;
}
