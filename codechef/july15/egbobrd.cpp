#include<bits/stdc++.h>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1=0,tmp2=0,tmp3=0,tmp=0,tmp4=0,tmp5=0,flag=0,T=0,N=0,Q=0,K=0
#define pb push_back
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
using namespace std;

int main() {
	var(ll);
	vl eat;
	ll brdCnt,localK;
	sc("%lld",&T);
	while(T--) {
		eat.clear();
		brdCnt=0,localK=0;
		sc("%lld %lld",&N,&K);
		fr(i,0,N) {
			sc("%lld",&tmp);
			eat.pb(tmp);
		}
		fr(i,0,N) {
			if(localK==0) {
				localK=K;
				brdCnt++;
			}
			if(eat[i]<localK) localK=localK-eat[i]-1;
			else if(eat[i]==localK) localK=0;
			else {
				eat[i]-=localK;
				if(eat[i]%K==0) {
					brdCnt+=(eat[i]/K);
					localK=0;
				}
				else {
					brdCnt+=(eat[i]/K);
					brdCnt++;localK=K;
					localK=localK-(eat[i]%localK)-1;
				}
			}
		}
		pf("%lld\n",brdCnt);
	}
	return 0;
}