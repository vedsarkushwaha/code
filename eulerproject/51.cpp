#include <cstdio>
#include <cmath>

#define sz 10000000
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

bool chkDig(int num) {
  int arr[10]={0};
  while(num) {
    arr[num%10]++;
    if(arr[num%10]>2 && (num%10)<3) return true;
    num/=10;
  }
  return false;
}

int main() {
  int i;
  seive_fun();
  for(i=0;i<1000000;i++) {
    if(prm[i]==0 && chkDig(i/10)) printf("%d\n",i);
  }
  return 0;
}
