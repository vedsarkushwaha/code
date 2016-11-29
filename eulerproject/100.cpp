#include<cstdio>
#include<cmath>

#define N 1000000000000
#define ll long long

using namespace std;

int main() {
  ll n = N;
  do {
    ll tmp = n*(n-1);
    if(tmp%2==0) {
      ll tmp1=tmp/2;
      ll tmp2=sqrt(tmp1);
      if(tmp2*(tmp2+1) == tmp1) {
        printf("%lld %lld\n",tmp1,tmp);
        break;
      }
    }
    n++;
  } while(true);
  return 0;
}
