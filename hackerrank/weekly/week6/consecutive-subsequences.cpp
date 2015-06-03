#include<cstdio>
#include<algorithm>
using namespace std;
int a[10000010],sum[10000010];
int main() {
	int n,i,j,flag,T,cnt,k,temp;
	scanf("%d",&T);
	while(T--) {
		cnt=0;
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sum[0]=0;
		for(i=1;i<=n;i++) {
			sum[i]=(sum[i-1]+a[i])%k;
			if(sum[i]==0) {
				cnt++;
			}
		}
		sort(sum,sum+n);
        temp=0;
		for(i=1;i<n;i++) {
			if(sum[i]==sum[i+1]) {
				temp++;
			}
            else {
                cnt+=((temp*(temp+1))/2);
                temp=0;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
