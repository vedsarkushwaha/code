#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MOD 1000000007
#define M 39

long long dp[M][M][M][M][5];

long long solve(int n1, int n2, int n3, int n4, int p) {
	long long a=0,b=0,c=0,d=0;
	if(dp[n1][n2][n3][n4][p] != -1)
		return dp[n1][n2][n3][n4][p];
	if (n1>0 && p != 1) {
		a = solve(n1-1, n2, n3, n4, 1);
	}
	if (n2>0 && p != 2) {
		b = solve(n1, n2-1, n3, n4, 2);
	}
	if (n3>0 && p != 3) {
		c = solve(n1, n2, n3-1, n4, 3);
	}
	if (n4>0 && p != 4) {
		d = solve(n1, n2, n3, n4-1, 4);
	}
	dp[n1][n2][n3][n4][p] = (a % MOD+b % MOD+c % MOD+d % MOD) % MOD;
	return dp[n1][n2][n3][n4][p];
}
int main() {
	int i,j,k,l,n1=M-1, n2=M-1, n3=M-1, n4=M-1;
	scanf("%d%d%d%d",&n1,&n2,&n3,&n4);
	
	for(i=0;i<=n1;i++)
		for (j=0;j<=n2;j++)
			for(k=0;k<=n3;k++)
				for(l=0;l<=n4;l++)
				{	
					dp[i][j][k][l][0] = -1;
					dp[i][j][k][l][1] = -1;
					dp[i][j][k][l][2] = -1;
					dp[i][j][k][l][3] = -1;
					dp[i][j][k][l][4] = -1;
				}
	
	dp[0][0][0][0][0] = 1;
	dp[0][0][0][0][1] = 1;
	dp[0][0][0][0][2] = 1;
	dp[0][0][0][0][3] = 1;
	dp[0][0][0][0][4] = 1;
	printf("%lld\n",solve(n1,n2,n3,n4,0));
}
