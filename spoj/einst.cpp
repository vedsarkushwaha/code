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
#define fr(i,m,n) for(i=m;i<n;i++)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1,tmp2,tmp3,tmp=0
#define MX 100000
using namespace std;

int main() {
	var(int);
	int T,X,N;
	vector<int> vec,dp,dm;
	sc("%d",&T);
	while(T--) {
		sc("%d %d",&X,&N);
		vec.clear();dp.clear();dm.clear();
		fr(i,0,N) {
			sc("%d",&tmp1);
			dm.push_back(tmp1);
		}
		dp.push_back(0);
		fr(i,1,X+1) {
			tmp2=MX;
			fr(j,0,N) {
				if(i-dm[j]<0)
					continue;
				else {
					tmp2=min(tmp2,dp[i-dm[j]]+1);
				}
			}
			dp.push_back(tmp2);
		}
		(dp.back()<MX) ? pf("%d\n",dp.back()) : pf("No solution\n");
		//fr(i,0,X+1)
			//pf("%d ",dp.at(i));
	}
	return 0;
}
