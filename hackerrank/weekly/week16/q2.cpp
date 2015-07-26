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
#define md 1000000007
using namespace std;

ll fact[1000001];
ll pw[10000000];
ll elv[65000];
ll power(ll x,ll y) {
	ll temp;
	if(y==0) return 1;
	temp=power(x, y/2);
	if (y%2 == 0)
		return (temp*temp) % md;
	else
		return (((x*temp)%md)*temp) % md;
}

void init() {
	fact[0]=1;
	fact[1]=1;
	var(ll);
	fr(i,2,1000001) {
		fact[i]=(fact[i-1]*i)%md;
	}
	pw[1]=1;

	elv[0]=0;
	elv[1]=1;
	fr(i,2,60100) elv[i]=(elv[i-1]*10+1)%md;
}

ll get_power(ll num) {
	if(num<10000000) {
		if(pw[num]!=0) return pw[num];
		else {
			pw[num]=power(num,md-2);
			return pw[num];
		}
	}
	else return power(num,md-2);
}

ll getdigi(ll x,ll y,ll z) {
	var(ll);
	tmp1=fact[x+y+z];
	tmp2=(((fact[x]*fact[y])%md)*fact[z])%md;
	
	tmp3=get_power(tmp2);
	return (tmp1*tmp3)%md;
}

ll calc(ll x,ll y,ll z) {
	var(ll);
	if(x==0 && y==0 && z==0) return 0;
	tmp=x+y+z;
	tmp1 = getdigi(x,y,z);
	tmp2 = elv[tmp];

	tmp3 = (4*x+5*y+6*z) % md;

	tmp4 = (tmp1*tmp2)%md;
	tmp4 = (tmp4*tmp3)%md;

	tmp=get_power(tmp);
	return (tmp4*tmp) % md;
}

int main() {
	var(ll);
	ll x,y,z;
	init();
	sc("%lld %lld %lld",&x,&y,&z);
	ll sm=0;
	fr(i,0,x+1) {
		fr(j,0,y+1) {
			fr(k,0,z+1) {
				sm=(sm+calc(i,j,k))%md;
			}
		}
	}
	pf("%lld\n",sm);
	return 0;
}