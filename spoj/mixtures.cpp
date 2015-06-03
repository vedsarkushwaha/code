#include<bits/stdc++.h>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1=0,tmp2=0,tmp3=0,tmp=0,tmp4=0,tmp5=0,flag=0,T=0,N=0
#define pb push_back
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
using namespace std;
pair<int,int> dp[101][101];
pair<int,int> calc(vi vec,int p,int q) {
	var(int);
	if(dp[p][q].second==INT_MAX) {
		if(p==q) {
			dp[p][q].first=vec[p];
			dp[p][q].second=0;
		}
		else if(q-p==1) {
			dp[p][q].first=(vec[p]+vec[q])%100;
			dp[p][q].second=vec[p]*vec[q];
			//pf("en");
		}
		else {
			fr(i,p,q) {
				if(dp[p][q].second>(calc(vec,p,i).second+calc(vec,i+1,q).second+calc(vec,p,i).first*calc(vec,i+1,q).first)) {
					dp[p][q].second=calc(vec,p,i).second+calc(vec,i+1,q).second+calc(vec,p,i).first*calc(vec,i+1,q).first;
					dp[p][q].first=(dp[p][i].first+dp[i+1][q].first)%100;
				}
			}
		}
	}
	return dp[p][q];
}
int main() {
	var(int);
	//sc("%d",&T);
	vi vec;
	while(sc("%d",&N)!=EOF) {
		vec.clear();
		fr(i,0,N) {
			sc("%d",&tmp);
			vec.pb(tmp);
		}
		//fr(i,0,vec.size())
			//pf("%d,",vec[i]);
		fr(i,0,101)
			fr(j,0,101) {
				dp[i][j].second=INT_MAX,dp[i][j].first=0;
			}
		pf("%d\n",calc(vec,0,N-1).second);
		/*fr(i,0,N) {
			fr(j,0,N) {
				pf("%d\t\t",dp[i][j].second);
			}
			pf("\n");
		}
		pf("\n");
		fr(i,0,N) {
			fr(j,0,N) {
				pf("%d\t\t",dp[i][j].first);
			}
			pf("\n");
		}*/
	}
	return 0;
}
