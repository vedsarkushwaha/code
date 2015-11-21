#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <climits>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1=0,tmp2=0,tmp3=0,tmp=0,tmp4=0,tmp5=0,flag=0
#define pb push_back
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
using namespace std;

int dp[4001][4001];
vector<int> vec[4001];
int main() {
	var(int);
	int N,M;
	sc("%d %d",&N,&M);
	fr(i,0,M) {
		sc("%d %d",&tmp1,&tmp2);
		dp[tmp1][tmp2]=1;
		dp[tmp2][tmp1]=1;
		vec[tmp1].pb(tmp2);
		vec[tmp2].pb(tmp1);
	}
	tmp=INT_MAX;
	fr(i,1,N+1) {
		if(vec[i].size()>=2) {
						// pf("Enter");
			
			fr(j,0,vec[i].size()) {
				fr(k,j+1,vec[i].size()) {
						// pf("Enter");

					if(dp[vec[i][j]][vec[i][k]]==1) {
						// pf("Enter");
						tmp1=vec[i].size()+vec[vec[i][j]].size()+vec[vec[i][k]].size();
						tmp=min(tmp,tmp1-6);
						flag=1;
					}
				}
			}
		}
	}
	if(flag) pf("%d\n",tmp);
	else pf("-1");
	return 0;
}