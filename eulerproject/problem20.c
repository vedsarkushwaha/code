#include<stdio.h>
int main() {
	char ch;
	int sum=0;
	while((ch=getchar())!='\n') {
		sum=sum+ch-'1'+1;
	}
	printf("%d",sum);
	return 0;
}
