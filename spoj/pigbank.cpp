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

int main() {
	var(int);
	int T,N;
	ll inf=100000000;
	ll dp[100000];
	vector<pair<int,int> > vec;
	sc("%d",&T);
	while(T--) {
		sc("%d %d",&tmp1,&tmp2);
		tmp=tmp2-tmp1;
		sc("%d",&N);
		vec.clear();
		fr(i,0,N) {
			sc("%d %d",&tmp1,&tmp2);
			vec.push_back(make_pair(tmp1,tmp2));
		}
		dp[0]=0;
		fr(i,1,tmp+1) {
			dp[i]=inf;
			fr(j,0,N) {
				if(i-vec[j].second>=0) {
					dp[i]=min(dp[i],dp[i-vec[j].second]+vec[j].first);
				}
				else {
					dp[i]=min(dp[i],inf);
				}				
			}
		}
		if(dp[tmp]>=inf)
			pf("This is impossible.\n");
		else
			pf("The minimum amount of money in the piggy-bank is %lld.\n",dp[tmp]);
	}	
	return 0;
}
