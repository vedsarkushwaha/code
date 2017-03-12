#include <cstdio>
#define ll long long
using namespace std;

int main() {
  int i,j,k,l,m,n,o,p,q;
  int nine[37]={0};
  int six[37]={0};
  for(i=1;i<=4;i++)
    for(j=1;j<=4;j++)
      for(k=1;k<=4;k++)
        for(l=1;l<=4;l++)
          for(m=1;m<=4;m++)
            for(n=1;n<=4;n++)
              for(o=1;o<=4;o++)
                for(p=1;p<=4;p++)
                  for(q=1;q<=4;q++)
                    nine[i+j+k+l+m+n+o+p+q]++;

  for(i=1;i<=6;i++)
    for(j=1;j<=6;j++)
      for(k=1;k<=6;k++)
        for(l=1;l<=6;l++)
          for(m=1;m<=6;m++)
            for(n=1;n<=6;n++)
              six[i+j+k+l+m+n]++;

  ll cnt=0;
  for(i=1;i<=36;i++) {
    ll sm=0;
    for(j=1;j<i;j++) {
      sm+=six[j];
    }
    cnt+=(nine[i]*sm);
  }
  printf("%lld\n",cnt);
}
