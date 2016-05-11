#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
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

ll IsPrime(ll num) {
	var(ll);
	fr(i,2,sqrt(num)+1) {
		if(num%i==0) return i;
	}
	return -1;
}

ll getNumberWithBase(ll num, ll base) {
	// This function will convert num into base base
	var(ll);
	pf("GetNumberWithBase: %lld ",num);
	tmp=0;
	i=0;
	while(num!=0) {
		if(num%2==1) {
			tmp+=pow(base,i);
		}
		num=num/2;
		i++;
	}
	pf("%lld %lld\n",base,tmp);
	return tmp;
}

pair<bool, vl> chkPrimeWithAllBase(ll num) {
	// This funcion will check prime in all base from 2 to 10
	var(ll);
	vl vec;
	fr(i,2,11) {
		tmp = getNumberWithBase(num,i);
		tmp = IsPrime(tmp);
		if(tmp!=-1) vec.pb(tmp);
		else flag=1;
		break;
	}
	if(flag) return make_pair(false, vec); 
	else return make_pair(true, vec);
}

void printVec(vl vec) {
	// This function will print the vector
	var(int);
	fr(i,0,vec.size()) {
		pf("%lld ", vec[i]);
	}
}

int main() {
	var(ll);
	ll N,J,T;
	sc("%lld",&T);
	fr(k,0,T) {
		ll num=4294967297, limit=8589934592;
		sc("%lld %lld",&N,&J);
		pair<bool, vl> pr;
		while(num<limit) {
			if(num%2==0) continue;
			pr = chkPrimeWithAllBase(num);
			pf("%lld %d\n",num,pr.first);
			if(pr.first==true) {
				pf("%lld ",getNumberWithBase(num,2));
				fr(i,2,11) {
					pf("%lld ",pr.second[i]);
				}
				pf("\n");
			}
			num++;
		}
	}
	return 0;
}