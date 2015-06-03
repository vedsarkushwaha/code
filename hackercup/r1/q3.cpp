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
ll mat[2001][2001];
ll mat1[2001][2001];
void build() {
	var(ll);
	fr(i,0,2001) {
		fr(j,0,i+1) {
			if(i==j)
				mat[i][j]=0;
			else if(j==0)
				mat[i][j]=1;
			else {
				mat[i][j]=(mat[i-1][j]+mat[i][j-1])%1000000007;
				//pf("%lld ",mat[i][j]);
			}
		}
	}
	fr(i,0,2001) {
		fr(j,i,2001) {
			if(i==0)
				mat1[i][j]=1;
			else if(i==j)
				mat1[i][j]=mat1[i-1][j];
			else
				mat1[i][j]=(mat1[i-1][j]+mat1[i][j-1])%1000000007;
		}
	}
}
int main() {
	var(ll);
	sc("%lld",&T);
	build();
	fr(i,1,T+1) {
		sc("%lld-%lld",&tmp1,&tmp2);
		pf("Case #%lld: %lld %lld\n",i,mat[tmp1][tmp2],mat1[tmp2][tmp2]);
	}
	return 0;
}
