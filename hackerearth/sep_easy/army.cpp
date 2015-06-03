/*******************
  	Akash Agrawall
	IIIT HYDERABAD
	***********************/
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<climits>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<stack>
#include<queue>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<functional>
#include<numeric>
#include<cassert>
using namespace std;
#define FOR(i,a,b) for(i= a ; i < b ; ++i)
#define rep(i,n) FOR(i,0,n)
#define INF INT_MAX
#define ALL(x) x.begin(),x.end()
#define LET(x,a) __typeof(a) x(a)
#define IFOR(i,a,b) for(LET(i,a);i!=(b);++i)
#define EACH(it,v) IFOR(it,v.begin(),v.end())
#define pb push_back
#define sz(x) int(x.size())
#define mp make_pair
#define fill(x,v) memset(x,v,sizeof(x))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define si(n) scanf("%d",&n)
#define pi(n) printf("%d ",n)
#define pd(n) printf("%lf ",n);
#define pdl(n) printf("%lf\n",n);
#define pin(n) printf("%d\n",n)
#define pln(n) printf("%lld\n",n)
#define pl(n) printf("%lld ",n)
#define sl(n) scanf("%lld",&n)
#define sd(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define scan(v,n) vector<int> v;rep(i,n){ int j;si(j);v.pb(j);}
#define mod (int)(1e9 + 7)
#define ll long long int
#define F first
#define S second
vector< pair<ll,ll> > arr;
vector< pair<ll,ll> > brr;
ll cnt=0,n;
void solve()
{
	ll i,sz,val,val1,temp;
	sz=arr.size();
	if(sz==0)
		return;
	brr.pb(mp(arr[0].F,arr[0].S));
	cnt=1;
	FOR(i,1,sz)
	{
		//printf("cnt=%lld\n",cnt);
		if(brr[cnt-1].S<arr[i].F)
		{
			brr.pb(mp(arr[i].F,arr[i].S));
			cnt++;
		}
		else
		{
			brr[cnt-1].S=max(brr[cnt-1].S,arr[i].S);
		}
		//printf("Here %lld %lld cnt=%lld\n",brr[cnt-1].F,brr[cnt-1].S,cnt);
	}
}
int main()
{
	ll s,e,x,p,i,ans=0,val,val1;
	sl(n);
	sl(s);
	sl(e);
	assert(n>=1 && n<=100000);
	assert(s>=1 && s<=1000000000000000000);
	assert(e>=1 && e<=1000000000000000000);
	assert(s<=e);
	rep(i,n)
	{
		sl(x);
		sl(p);
		assert(x>=1 && x<=1000000000000000000);
		assert(p>=1 && p<=1000000000000000000);
		assert(x+p<=1000000000000000000);
		val=x-p;
		val1=x+p;
		if(val1<=s || val>=e)
			continue;
		if(val<=s)
			val=s;
		if(val1>=e)
			val1=e;
		arr.pb(mp(val,val1));
	}
	/*rep(i,n)
		printf("%lld %lld\n",arr[i].F,arr[i].S);*/
	sort(arr.begin(),arr.end());
	/*rep(i,n)
		printf("%lld %lld\n",arr[i].F,arr[i].S);*/
	solve();
	//printf("cnt=%lld\n",cnt);
	/*rep(i,cnt)
		printf("%lld %lld\n",brr[i].F,brr[i].S);*/
	rep(i,cnt)
	{
		val=brr[i].F;
		val1=brr[i].S;
		/*if(val<=s)
			val=s;
		if(val1>=e)
			val1=e;*/
		ans+=val1-val;
		//printf("i=%lld val=%lld val1=%lld cnt=%lld\n",i,val,val1,cnt);
	}
	ans=(e-s)-ans;
	if(ans<0)
		ans=-1;
	pln(ans);
	return 0;
}
