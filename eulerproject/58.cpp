#include <cstdio>
#include <vector>
#include <set>
#include <cmath>

#define ll long long
using namespace std;

bool chkPrime(ll num) {
  ll limit=sqrt(num)+1;
  ll i;

  if(num==2 || num==3) return true;
  if(num%2==0 || num%3==0) return false;
  if(num<25) return true;
  if(((num-1)%6)!=0 && ((num+1)%6)!=0) return false;

  for(i=2;i<=limit;i++) {
    if(num%i==0) return false;
  }
  return true;
}

int main() {
  ll i=1;
  int primeCnt=0;
  ll tmp,diff;

  while(1) {
    tmp = 2*i+1;
    diff = tmp-1;
    if(chkPrime(tmp*tmp)) primeCnt++;
    if(chkPrime(tmp*tmp - diff)) primeCnt++;
    if(chkPrime(tmp*tmp - 2*diff)) primeCnt++;
    if(chkPrime(tmp*tmp - 3*diff)) primeCnt++;

    printf("%lld %lld %d %lld\n",i,2*i+1, primeCnt, 1+i*4);
    if(1+i*4 > primeCnt*10) {
      printf("%lld",2*i+1);
      break;
    }
    i++;
  }
  return 0;
}
