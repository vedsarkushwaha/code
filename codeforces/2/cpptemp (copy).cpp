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
	var(ll);
	map<int,int> mp;
	mp[1]=1;
	mp[2]=2;
	mp[3]=3;
	mp[4]=4;
	mp[5]=5;
	mp[6]=6;
	if(mp.find(1)!=mp.end())
		pf("Found");
	map<int,int>::iterator it;
	for(it=mp.begin();it!=mp.end();++it) {
		pf("%d %d\n",it->first,it->second);
	}
	return 0;
}