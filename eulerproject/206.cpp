#include <cstdio>
#define ll long long

using namespace std;

bool chk(ll num) {
  if(num%10==9) {
    num=num/100;
    if(num%10==8) {
      num=num/100;
      if(num%10==7) {
        num=num/100;
        if(num%10==6) {
          num=num/100;
          if(num%10==5) {
            num=num/100;
            if(num%10==4) {
              num=num/100;
              if(num%10==3) {
                num=num/100;
                if(num%10==2) {
                  num=num/100;
                  if(num%10==1) {
                    return true;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return false;
}

int main() {
  ll num;
  ll i,j,k;
  for(i=100000000;i<=1000000000;i++) {
    if(chk(i*i)) printf("%lld\n",i);
  }
  return 0;
}
