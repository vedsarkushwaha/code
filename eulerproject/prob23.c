#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int abd_num[30000];
int chk_abd(int x) {
	int sum=1,limit,i;
	limit=sqrt(x);
	if((x==1)||(x==2))
		return 0;
	for(i=2;i<=limit;i++) {
		if(x%i==0) {
			if(i==x/i)
				sum+=i;
			else {
				sum+=(x/i);
				sum+=i;
			}
		}
	}
	//return sum;
	if(sum>x) return 1;
	else return 0;
}
int chk_sum(int x) {
	int i;
	for(i=1;i<x;i++) {
		if((abd_num[i]==1)&&(abd_num[x-i]==1))
			return 1;
	}
	return 0;
}
int main() {
	int n,i;
	long long sum=0;
	for(i=1;i<=28123;i++)
		abd_num[i]=chk_abd(i);
	printf("\n");
	i=28120;
	//for(i=1;i<=28123;i++)
	if(!chk_sum(i))
		printf("%d",i);
	return 0;
}
