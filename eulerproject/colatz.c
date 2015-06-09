#include<stdio.h>
int arr[10000001];
long long start_seq(int s) {
	long long seq,cnt=1;
	seq=s;
	while(seq!=1) {
		if(seq%2==0) {
			seq=seq/2;
		}
		else {
			seq=3*seq+1;
		}
		cnt++;
	}
	return cnt;
}
int main() {
	int i,num;
	long long cnt,max=0;
	for(i=1;i<=1000000;i++) {
		if(arr[i]==0) {
			cnt=start_seq(i);
		}
		if(max<cnt) {
			max=cnt;
			num=i;
		}
	}
	printf("%d",num);
	return 0;
}