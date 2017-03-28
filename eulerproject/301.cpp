#include <cstdio>
#define ll long long

using namespace std;

ll range=1073741824L;

int main() {
  ll n=0;
  ll cnt=0;
  ll tmp;
  while(n<=range) {
    n++;
    if(n^(2*n)^(3*n)) {
      cnt++;
    }
  }
  printf("%lld",range-cnt);
  return 0;
}
