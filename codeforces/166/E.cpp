#include <cstdio>

#define ll long long
using namespace std;

int main() {
  ll i,n;
  ll A,B,C,D,nA,nB,nC,nD;
  ll md = 1000000007;

  scanf("%lld",&n);

  A = 0;
  B = 0;
  C = 0;
  D = 1;

  for(i=1;i<=n;i++) {
    nA = (B + C + D) % md;
    nB = (A + C + D) % md;
    nC = (A + B + D) % md;
    nD = (A + B + C) % md;

    A = nA;
    B = nB;
    C = nC;
    D = nD;
  }
  printf("%lld\n",D);

  return 0;
}
