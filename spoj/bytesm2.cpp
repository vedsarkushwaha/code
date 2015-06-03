#include<cstdio>
#include<iostream>
#include<vector>
#include<stack>
#include<map>
#include<set>
#include<cstring>
#include<cmath>
#include<string>
#include<cstdlib>
#include<queue>
#include<algorithm>
#include<climits>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1,tmp2,tmp3,tmp=0,T
using namespace std;

int main() {
	var(int);
	int h,w;
	int inp[110][110],dp[110][110];
	sc("%d",&T);
	while(T--) {
		sc("%d %d",&h,&w);
		fr(i,0,110) {
			fr(j,0,110) {
				inp[i][j]=0;
				dp[i][j]=0;
			}
		}
		fr(i,5,h+5) {
			fr(j,5,w+5) {
				sc("%d",&tmp);
				inp[i][j]=tmp;
			}
		}
		//print inp
		/*fr(i,5,h+5) {
			fr(j,5,w+5) {
				pf("%d ",inp[i][j]);
			}
			pf("\n");
		}*/
		fr(i,5,h+5) {
			fr(j,5,w+5) {
				//if(i==5)
					//dp[i][j]=inp[i][j];
				//else
				dp[i][j]=inp[i][j]+max(dp[i-1][j],max(dp[i-1][j-1],dp[i-1][j+1]));
			}
		}
		//print dp
		/*pf("\n");
		fr(i,5,h+5) {
			fr(j,5,w+5) {
				pf("%d ",dp[i][j]);
			}
			pf("\n");
		}*/
		tmp3=0;
		fr(j,5,w+5) {
			tmp3=max(tmp3,dp[h+4][j]);
		}
		pf("%d\n",tmp3);
	}
	return 0;
}
