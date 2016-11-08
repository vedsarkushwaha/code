#include <cstdio>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>

#define ll long long
using namespace std;

bool chkSqr(ll num) {
  ll tmp = sqrt(num);
  if(tmp*tmp == num) return true;
  else return false;
}

int main() {
  ll x,D;
  ll y,tmp;
  ll mixmaxx=0;
  for(D=2;D<=1000;D++) {
    if(chkSqr(D)) {
      printf("%lld is square\n",D);
      continue;
    }
    x=2;
    while(1) {
      if((((x*x-1) % D) == 0) && chkSqr((x*x-1) / D)) {
        tmp = (x*x-1) / D;
        y=sqrt(tmp);
        printf("%lld %lld %lld\n",x,D,y);
        mixmaxx = max(mixmaxx, x);
        break;
      }
      else x++;
    }
  }
  printf("%lld\n", mixmaxx);
  return 0;
}
