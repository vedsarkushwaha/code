#include <cstdio>
#include <vector>
#include <cassert>

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

ll md=1000000007;
ll fact[1000001];

void print(vl vec) {
	var(ll);
	pf("\n");
	pf("\n");
	fr(i,0,vec.size()) pf("%lld ",vec[i]);
	pf("\n");
	pf("\n");
}

ll power(ll x,ll y) {
	ll temp;
	if(y==0) return 1;
	temp=power(x, y/2);
	temp = (temp*temp)%md;
	if (y%2 == 0)
		return temp;
	else
		return (x*temp)%md;
}

ll getFact(ll num) {
	var(ll);
	if(num==0 || num==1) return 1;
	if(fact[num]) return fact[num];
	tmp=getFact(num-1)%md;
	return (tmp*num)%md;
}

ll getMod(ll num) {
	var(ll);
	// num=getFact(num);
	tmp = power(num,md-2);
	return tmp;
}

int main() {
	var(ll);
	ll N,x,M,T;
	sc("%lld",&T);
	while(T--) {
		sc("%lld %lld %lld",&N,&x,&M);
		M=M%md;
		vl vec,series;
		tmp1=1;
		series.pb(tmp1);
		// pf("\n");
		fr(i,0,N) {
			sc("%lld",&tmp);
			tmp=tmp%md;
			vec.pb(tmp);
			
			// tmp=i+1;
			
			tmp1*=(M+i);
			tmp1=tmp1%md;
			// pf("%lld %lld %lld\n",tmp1,i+1,tmp1/(i+1));
			// assert(tmp1%(i+1)==0);
			tmp1*=getMod(i+1);
			tmp1=tmp1%md;
			// pf("%lld ",tmp1);
			// if(i==0) tmp1=(tmp1*1)%md;
			// else tmp1=(tmp1*i)%md;
			// tmp1=tmp1*getMod(tmp);
			// tmp1=tmp1%md;
			// pf("%lld %lld %lld\n",tmp1,tmp,getMod(tmp));
			series.pb(tmp1);
			// if(i) assert(tmp1%(i+1)==0);
		}
		// print(series);
		ll ans=0;
		fr(i,0,x) {
			if(i==0) tmp=1;
			else tmp=i;
			// assert(vec[x-1-i]*series[i]%tmp==0);
			ans+=((vec[x-1-i]*series[i])%md);
			ans=ans%md;
			// pf("%lld\n",ans);
		}
		pf("%lld\n",ans);
	}
	return 0;
}