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
	sc("%d",&N);
	string ply[N];
	pair<string,int> game[N];
	map<string,int> mp;
	int mx=0;
	string P;
	fr(i,0,N) {
		cin>>P;
		sc("%d",&tmp);
		game[i].first=P;
		game[i].second=tmp;
		if(mp.find(P)!=mp.end()) {
			mp[P]+=tmp;
		}
		else
			mp[P]=tmp;
	}
	//get max value
	mx=0;
	map<string,int>::iterator it;
	for(it=mp.begin();it!=mp.end();++it) {
		if(it->second>mx)
			mx=it->second;
	}
	//get max player
	map<string,int> win; 
	for(it=mp.begin();it!=mp.end();++it) {
		if(it->second==mx) {
			win[it->first]=1;
			// cout<<it->first<<endl;
		}
	}
	mp.clear();
	fr(i,0,N) {
		if(mp.find(game[i].first)!=mp.end()) {
			mp[game[i].first]+=game[i].second;
		}
		else
			mp[game[i].first]=game[i].second;
		if(mx<=mp[game[i].first] && win[game[i].first]==1) {
			cout<<game[i].first;
			return 0;
		}
	}
	return 0;
}
