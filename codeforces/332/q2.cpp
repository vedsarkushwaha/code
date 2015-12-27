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

bool comp(pair<int,int> pr, int val) {
	return (pr.first) < val;
}

int main() {
	var(int);
	int n,m;
	vi b;
	vii f;
	int arr[100010]={0};
		
	sc("%d %d",&n,&m);

	fr(i,0,n) {
		sc("%d",&tmp);
		f.pb(make_pair(tmp,i+1));
		if(arr[tmp]==1) {
			flag=1;
		}
		else {
			assert(arr[tmp]==0);
			arr[tmp]=1;
		}
	}
	
	fr(i,0,m) {
		sc("%d",&tmp);
		b.pb(tmp);
		if(!arr[tmp]) {
			pf("Impossible");
			return 0;
		}
	}
	if(flag) {
		pf("Ambiguity");
		return 0;
	}
	pf("Possible\n");
	sort(f.begin(),f.end());
	fr(i,0,b.size()) {
		pf("%d ",lower_bound(f.begin(),f.end(),b[i],comp)->second);
	}
	
	return 0;
}