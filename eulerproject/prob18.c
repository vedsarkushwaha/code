#include<stdio.h>
int main() {
	int sum[100],i,j,temp_arr[100],max,n,t;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		for(i=0;i<n;i++) {
			sum[i]=0;
			temp_arr[i]=0;
		}
		for(i=0;i<n;i++) {
			for(j=0;j<=i;j++) {
				scanf("%d",&temp_arr[j]);
				if(i==0) {
					sum[0]=temp_arr[0];
					sum[1]=temp_arr[0];
				}
				else {
					temp_arr[j]+=sum[j];
					if(j==0)
						sum[j]=temp_arr[j];
					if(j==i)
						sum[j+1]=temp_arr[j];
					if(j!=0) {
						if(temp_arr[j]>temp_arr[j-1])
							sum[j]=temp_arr[j];
						else
							sum[j]=temp_arr[j-1];
					}
				}
			}
		}
		for(i=0;i<n;i++) {
			if(i==0)
				max=sum[i];
			else {
				if(max<sum[i])
					max=sum[i];
			}
		}
		printf("%d\n",max);
	}
	return 0;
}