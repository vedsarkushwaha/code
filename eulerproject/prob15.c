#include<stdio.h>
int main() {
	int sum=2,i;
	for(i=2;i<=20;i++) {
		sum=2*sum+2*(i-1);
		printf("%d ",sum);
	}
	return 0;
}