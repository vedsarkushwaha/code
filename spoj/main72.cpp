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
#define var(x) x i=0,j=0,k=0,tmp1,tmp2,tmp3,tmp=0
using namespace std;
bool dp[1001][100001];
int main() {
	var(int);
	int N,T;
	sc("%d",&T);
	vector<int> vec;
	while(T--) {
		sc("%d",&N);
		tmp3=0;
		vec.clear();
		fr(i,0,N) {
			sc("%d",&tmp);
			vec.push_back(tmp);
			tmp3+=tmp;
		}
		fr(i,0,N+1) {
			fr(j,0,tmp3+1) {
				if((i==0)||(j==0)) {
					dp[i][j]=0;
				}
				else if(vec[i-1]==j)
					dp[i][j]=1;
				else if(j-vec[i-1]>=0) {
					dp[i][j]=dp[i-1][j]||dp[i-1][j-vec[i-1]];
				}
				else
					dp[i][j]=dp[i-1][j];
			}
		}
		tmp=0;
		fr(j,0,tmp3+1) {
			if(dp[N][j]==1)
				tmp+=j;
		}
		pf("%d\n",tmp);
	}
	return 0;
}
