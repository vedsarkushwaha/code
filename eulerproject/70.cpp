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

bool chkPerm(int n, int m) {
  int arrn[10]={0};
  int arrm[10]={0};

  while(n!=0) {
    arrn[n%10]++;
    n=n/10;
  }
  while(m!=0) {
    arrm[m%10]++;
    m=m/10;
  }

  // for(int i=0;i<10;i++) {
  //   printf("%d %d\n",arrn[i],arrm[i]);
  // }

  for(int i=0;i<10;i++) {
    if(arrn[i]!=arrm[i]) return false;
  }
  return true;
}

int main() {
  int i,j,k;
  int p,val;
  double tmp=-1,tmp1=-1;

  // if(chkPerm(87109,79180)) printf("permute");
  // else printf("No permute");

  for(i=2;i<10000000;i++) {
    if(i%1000000==0) printf("i=%d\n",i);
    p = phi(i);
    if(chkPerm(p,i)) {
      // printf("%d %d are permut\n",p,i);
      tmp = (double)i/phi(i);
      if(tmp1==-1) {
        tmp1 = tmp;
      }
      else if(tmp<=tmp1) {
        tmp1 = tmp;
        val = i;
      }
    }
  }
  printf("%d",val);
  return 0;
}
