#include <cstdio>
#include <cmath>

using namespace std;

int phi(int n) {
  int result = n;
  for(int i = 2; i * i <= n; ++i)
    if(n % i == 0) {
      while(n % i == 0)
          n /= i;
      result -= result / i;
    }
  if(n > 1)
    result -= result / n;
  return result;
}

int main() {
  int i,j,k;
  int val;
  double tmp=0,tmp1=0;
  printf("%d %d %d\n",phi(1),phi(2),phi(3));
  for(i=1;i<=1000000;i++) {
    tmp = (double)i/phi(i);
    if(tmp>tmp1) {
      tmp1 = tmp;
      val = i;
    }
  }
  printf("%d",val);
  return 0;
}
