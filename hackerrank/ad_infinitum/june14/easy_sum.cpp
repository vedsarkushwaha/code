#include<cstdio>
using namespace std;
int main() {
	int T,N,M,rem,que;
	unsigned long long sum;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&N,&M);
		rem=N%M;
		que=N/M;
		sum=((long long)(M-1)*(M))/2;
		sum*=que;
		rem=N%M;
		sum+=((long long)rem*(rem+1))/2;
		printf("%llu\n",sum);
	}
	return 0;
}
