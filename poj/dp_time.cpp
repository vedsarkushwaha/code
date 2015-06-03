#include<cstdio>
using namespace std;
int main() {
	unsigned long long dp[1000001];
	dp[1]=1;dp[2]=1;dp[3]=2;dp[4]=4;
	int i,T,N;
	for(i=5;i<=1000000;i++) {
		dp[i]=dp[i-1]+dp[i-3]+dp[i-4];
	}
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&N);
		printf("%llu\n",dp[N]);
	}
	return 0;
}
