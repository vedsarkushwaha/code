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
	var(int);
	sc("%d",&T);
	while(T--) {
		sc("%d",&N);
		vi vec;
		vi chk;
		chk.resize(N,0);
		fr(i,0,N) {
			sc("%d",&tmp);
			vec.pb(tmp);
		}
		fr(i,0,N-1) {
			if(vec[i]!=vec[i+1]) {
				chk[i]=1;
				chk[i+1]=1;
			}
		}
		tmp5=0;
		fr(i,0,N)
			if(chk[i]!=0)
				tmp5++;
		pf("%d\n",tmp5);
	}
	return 0;
}