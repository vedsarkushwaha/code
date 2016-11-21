#include <cstdio>
#include <cmath>

#define ll long long
using namespace std;

ll getHexa(ll n) {
  return n*(2*n-1);
}

bool isTri(ll n) {
  ll i = (sqrt(8*n+1) - 1)/2;
  return (i*(i+1))/2 == n;
}

bool isPenta(ll n) {
  ll i=(sqrt(24*n+1)+1)/6;
  return (i*(3*i-1))/2 == n;
}

bool isHexa(int n) {
  ll i = (sqrt(8*n+1)+1)/4;
  return i*(2*i-1) == n;
}

int main() {
  ll i=1;
  ll hexa;
  while(1) {
    hexa = getHexa(i++);
    if(isPenta(hexa)) {
      printf("%lld\n",hexa);
    }
  }
  return 0;
}
