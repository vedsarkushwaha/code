#include <cstdio>
#include <cmath>
#include <algorithm>

#define ll long long
#define sz 100000000
using namespace std;

int prm[sz+1];

void seive_fun() {
	int i,j,k,limit;
	prm[0]=1;
	prm[1]=1;
	limit=sqrt(sz);
	for(i=2;i<=limit;i++) {
		if(prm[i]==0) {
			k=sz/i;
			for(j=2;j<=k;j++)
				prm[i*j]=1;
		}
	}
}

int main() {
	seive_fun();
  int n=100000000;
  int i,j,k,cnt,m,ans=0;
  for(i=2;i<=n;i++) {
    // get prime factors of i with count
    j=i;
    m=0;
    for(k=0;k<=sqrt(j)+1;k++) {
      if(!prm[k] && j%k==0) {
        cnt=0;
        while(j%k==0) {
          j=j/k;
          cnt++;
        }
        m=max(m,cnt*k);
      }
    }
    if(j!=1) m=max(m,j);
    // printf("%d %d\n",i,m);
    ans+=m;
  }
  printf("%d\n",ans);
  return 0;
}
