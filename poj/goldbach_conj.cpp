#define sz 1000000
#include<cstdio>
#include<cmath>
using namespace std;
int prm[sz+1];
void init() {
	int i;
	for(i=0;i<=sz;i++)
		prm[i]=1;
	prm[0]=0;
	prm[1]=0;
}
void seive_fun() {
	int i,j,k,limit;
	init();
	limit=int(sqrt(double(sz)));
	for(i=2;i<=limit;i++) {
		if(prm[i]==1) {
			k=sz/i;
			for(j=2;j<=k;j++)
				prm[i*j]=0;
		}
	}
}
void prnt_arr() {
	int i;
	for(i=0;i<=sz;i++)
		printf("%d ",prm[i]);
}
int main() {
	int i,n,sum;
	seive_fun();
	while((scanf("%d",&n)!=EOF) && (n!=0)) {
		for(i=2;i<=sz;i++) {
			if((prm[i]==1) && (prm[n-i]==1)) {
				printf("%d = %d + %d\n",n,i,n-i);
				break;
			}
		}
	}
	return 0;
}
