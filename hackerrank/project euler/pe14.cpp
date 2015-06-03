#include<stdio.h>
long unsigned int arr[10000001];
long unsigned int start_seq(int s) {
	long unsigned seq,cnt=0;
	seq=(long unsigned)s;
	while(1) {
		if(arr[seq]!=0)
			return cnt+arr[seq];
		if(seq%2==0) {
			seq=seq/2;
		}
		else {
			seq=3*seq+1;
		}
		cnt++;
	}
}

int main() {
	long unsigned i,num,j,T,nm;
	long unsigned cnt,max=0L;
	arr[1]=1;
	scanf("%lu",&T);
	while(T--) {
		scanf("%lu",&i);
		max=0;
		//printf("%d %d",i,j);
		for(num=1;num<=i;num++) {
			if(arr[num]==0) {
				cnt=start_seq(num);
				arr[num]=cnt;
				j=num;
				//printf("%lld %d\n",cnt,num);
			}
			else {
				cnt=arr[num];
				j=num;
			}
			if(max<=cnt) {
				//printf("max=%lld ",max);
				max=cnt;
				nm=j;
			}
		}
		printf("%lu\n",nm);
	}
	return 0;
}
