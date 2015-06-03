#include<cstdio>
#include<iostream>
using namespace std;
int main() {
	int N,cnt=0,ele,max=0;
	scanf("%d",&N);
	while(N--) {
		scanf("%d",&ele);
		printf(" %d ",ele);
		if(ele==0) {
			if(cnt>max)
				max=cnt;
			cnt=0;
		}
		else {
			printf("CNT");
			cnt++;
		}
	}
	printf("%d",cnt);
	if(cnt>max)
		max=cnt;
	//printf("%d\n",max);
	return 0;
}
