#include<stdio.h>
int a[10010],sum[10010];
int main() {
	int n,i,j,flag;
	while(scanf("%d",&n)!=EOF) {
		flag=0;
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sum[0]=0;
		for(i=1;i<=n;i++) {
			sum[i]=(sum[i-1]+a[i])%n;
			if(sum[i]==0) {
				printf("%d\n",i);
				for(j=1;j<=i;j++)
					printf("%d\n",a[j]);
				flag=1;
				break;
			}
		}
		if(flag==0) {
			for(i=1;i<=n;i++) {
				for(j=i+1;j<=n;j++) {
					if(sum[i]==sum[j]) {
						printf("%d\n",j-i);
						for(++i;i<=j;i++) {
							printf("%d\n",a[i]);
						}
						flag=1;
						goto over;
					}
				}
			}
		}
		over:
		if(!flag)
			printf("0\n");
	}
	return 0;
}