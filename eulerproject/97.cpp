#include <cstdio>

#define ll long long
#define md 10000000000
using namespace std;

int main() {
  int i,j;
  int pwr=7830457;
  ll num=28433;
  // int pwr=10;
  ll n=1;
  for(i=1;i<=pwr;i++) {
    n=n<<1;
    printf("%lld-",n);
    n=n%md;
    printf("%lld\n",n);
  }

  printf("%lld\n",(n*num)%md);
  return 0;
}
