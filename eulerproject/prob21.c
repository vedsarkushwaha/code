#include<stdio.h>
#include<math.h>
int arr[30001]={0,0,1};
int calc_div(int x) {
	int temp,i,sum=1,temp1;
	temp=sqrt(x);
	for(i=2;i<=temp;i++) {
		if(x%i==0) {
			temp1=x/i;
			if(temp1==i) 
				sum+=i;
			else
				sum+=i+temp1;
		}
	}
	return sum;
}
void prnt() {
	int i;
	for(i=3;i<=30000;i++)
		printf("%d %d\n",i,arr[i]);
}
int main() {
	int i,j,temp;
	long sum=0;
	for(i=3;i<=30000;i++) {
		arr[i]=calc_div(i);
		//printf("%d %d\n",i,arr[i]);
	}
//	prnt();
	for(i=3;i<=10000;i++) {
		temp=arr[i];
		if(temp==i)
			continue;
		if(arr[temp]==i) {
			sum+=i;
			//printf("%d %d\n",i,temp);
		}
	}
	printf("%ld",sum);
	return 0;
}
