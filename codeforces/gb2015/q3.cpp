#include <cstdio>
#include <cassert>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1=0,tmp2=0,tmp3=0,tmp=0,tmp4=0,tmp5=0,flag=0,T=0,N=0,Q=0

using namespace std;

int main() {
	var(int);
	int h,w;
	sc("%d %d\n",&h,&w);
	char inp[h+2][w+2],ch;
	int dp[h+2][w+2];
	fr(i,0,h+2) {
		fr(j,0,w+2) {
			if(j==0 || j==w+1 || i==0 || i==h+1) {
				dp[i][j]=0;
				inp[i][j]='#';
				continue;
			}
			// pf("%d %d ",i,j);
			sc("%c",&ch);
			inp[i][j]=ch;
			// pf("%c\n",ch);
			if(inp[i][j]=='#') {
				dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
			}
			else {
				assert(inp[i][j]=='.');
				if(inp[i][j-1]=='.' && inp[i-1][j]=='.') {
					dp[i][j]=dp[i][j-1]+dp[i-1][j] - dp[i-1][j-1] + 2;
				}
				else if(inp[i][j-1]=='#' && inp[i-1][j]=='.') {
					dp[i][j]=dp[i][j-1]+dp[i-1][j] - dp[i-1][j-1] + 1;
				}
				else if(inp[i][j-1]=='.' && inp[i-1][j]=='#') {
					dp[i][j]=dp[i][j-1]+dp[i-1][j] - dp[i-1][j-1] + 1;
				}
				else if(inp[i][j-1]=='#' && inp[i-1][j]=='#') {
					dp[i][j]=dp[i][j-1]+dp[i-1][j] - dp[i-1][j-1];
				}
				else assert(1==0);
			}
		}
		if(i!=0 && i!=h+1) sc("%c",&ch);
	}

	// fr(i,0,h+2) {
	// 	fr(j,0,w+2) {
	// 		pf("%c ",inp[i][j]);
	// 	}
	// 	pf("\n");
	// }
	// pf("\n");
	// fr(i,0,h+2) {
	// 	fr(j,0,w+2) {
	// 		pf("%d ",dp[i][j]);
	// 	}
	// 	pf("\n");
	// }

	int q;
	sc("%d",&q);
	while(q--) {
		int l1,r1,l2,r2;
		sc("%d %d %d %d",&l1,&r1,&l2,&r2);
		tmp = dp[l2][r2] + dp[l1-1][r1-1] - dp[l1-1][r2] - dp[l2][r1-1];
		fr(i,l1,l2+1) {
			if(inp[i][r1]==inp[i][r1-1] && inp[i][r1]=='.') tmp--;			
		}
		fr(i,r1,r2+1) {
			if(inp[l1][i]==inp[l1-1][i] && inp[l1][i]=='.') tmp--;
		}
		pf("%d\n",tmp);
	}
	return 0;
}