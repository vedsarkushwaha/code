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
bool comp(int i,int j) {
	return j<i;
}
int main() {
	vl kay,cat,whl;
	ll S;
	var(ll);
	sc("%lld %lld",&N,&S);
	fr(i,0,N) {
		sc("%lld %lld",&tmp1,&tmp2);
		if(tmp1==1) {
			cat.pb(tmp2);
		}
		else {
			kay.pb(tmp2);
		}
	}
	sort(cat.begin(),cat.end(),comp);
	sort(kay.begin(),kay.end(),comp);
	i=0,j=0;
	tmp4=1;
	string st;
	while(S>1) {
		if(j+1==cat.size()) {
			tmp4=0;
		}
		else if(j==cat.size() || i==kay.size())
			break;
		if(kay[i]>=cat[j]+tmp4*(cat[j+tmp4])) {
			S-=2;
			st+='2';
			tmp5+=kay[i];
			i++;
		}
		else {
			S-=1;
			st+='1';
			tmp5+=cat[j];
			j++;
		}
		// pf("%lld %lld\n",S,tmp5);
		// fflush(stdout);
	}
	if(j==cat.size()) {
		while(i!=kay.size() && S>1) {
			tmp5+=kay[i];
			st+='2';
			i++;
			S-=2;
		}
	}
	else if(i==kay.size()) {
		while(j!=cat.size() && S>0) {
			tmp5+=cat[j];
			j++;
			S-=1;
			st+='1';
		}	
	}
	if(j!=cat.size() && S>0) {
		tmp5+=cat[j];
		st+='1';
	}
	pf("%lld\n",tmp5);
	cout<<st;
	return 0;
}