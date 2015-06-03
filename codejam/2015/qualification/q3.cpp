#include<bits/stdc++.h>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1=0,tmp2=0,tmp3=0,tmp=0,tmp4=0,tmp5=0,flag=0,T=0,N=0,Q=0
#define pb push_back
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
using namespace std;

int main() {
	var(ll);
	string str,str1;
	ll L,X;
	ll data[5][5]={{1,2,3,4}},{2,-1,4,-3},{3,-4,-1,2},{4,3,-2,-1}};
	sc("%d",&T);
	fr(k,1,T+1) {
		tmp5=0;
		sc("%d %d",&L,&X);
		cin>>str1;
		fr(i,0,X)
			str+=str1
		int arr[L*X];
		fr(i,0,str.length())
			arr[i]=arr[i]-'i'+2;
		int dp[L*X][L*X];
		fr(i,0,L*X) {
			fr(j,0,L*X) {
				if(i==j)
					dp[i][j]=arr[i];
				else
					dp[i][j]=data[dp[i][j-1]][arr[j]];
			}
		}
		vi veci,veck;
		fr(i,0,L*X) {
			if(dp[0][i]==2)
				veci.pb(i);
		}
		ifr(i,L*X-1,-1)
			if(dp[L*X-1][i]==4)
				veck.pb(k);
		fr(i,0,veci.size()) {
			fr(j,0,vecj.size()) {
				if(veci[i]<vecj[i]) {
					if(dp[veci[i]+1][vecj[i]-1]==3) {
						tmp5=1;
						break;
					}
				}
			}
			if(tmp5==1)
				break;
		}
		if(tmp5==1)
			pf("Case %d: YES\n",k);
		else
			pf("Case %d: NO\n",k);
	}
	return 0;
}
