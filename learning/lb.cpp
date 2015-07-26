#include<bits/stdc++.h>
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

int main() {
	var(int);
	vi vec;
	vi::iterator it,it1;
	int T,N;
	sc("%d",&T);
	sc("%d",&N);
	fr(i,0,N) {
		sc("%d",&tmp);
		vec.pb(tmp);
	}
	sort(vec.begin(),vec.end());
	while(T--) {
		sc("%d",&tmp);
		it=lower_bound(vec.begin(),vec.begin()+3,tmp);
		it1=upper_bound(vec.begin(),vec.begin()+3,tmp);
		if(it==vec.begin()+3) {
			it--;
			pf("%d-",*it);
			pf("Not Found\n");
		}
		else pf("%d\n",*it);
		if(it1==vec.begin()+3) {
			it1--;
			pf("%d-",*it1);
			pf("Not Found\n");
		}
		else pf("%d\n",*it1);
	}
	return 0;
}