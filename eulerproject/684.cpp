#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

long long md=1000000007;

vector<long long> nineVec;

long long nineWithMod() {
  long long i;
  for(i=1;i<=30;i++) {

  }
}

long long sn(long long n) {

  long long temp = n;
  long long ans = 0;

  long long nineCount = temp/9;
  long long lastDigit = temp - nineCount*9;

  printf("Nine Count : %lld\n", nineCount);

  ans = lastDigit;
  for(int i=0;i<nineCount;i++) {
    ans=(ans*10+9)%md;
  }
  return ans;
}

int main() {
  long long ans=0;
  long long faba, fabb, fabc;
  int i=2;
  long long j=90;
  faba=0; fabb=1;
  while(i<=90) {
    fabc=faba+fabb;
    faba=fabb;
    fabb=fabc;

    ans = (ans + sn(fabc) * j) % md;

    printf("%lld %lld %lld\n", j, fabc, ans);

    i++;
    j--;
  }
  printf("%lld",ans);
  return 0;
}
