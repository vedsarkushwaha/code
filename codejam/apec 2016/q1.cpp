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
	int T,M;
	string str1,str2;
	sc("%d",&T);
	fr(i,1,T+1) {
		sc("%d",&M);
		map<string,int> vis;
		map<string,vector<string> > mp;
		map<string,vector<string> >::iterator it;
		fr(i,0,M) {
			cin>>str1>>str2;
			vis.insert(make_pair(str1,0));
			vis.insert(make_pair(str2,0));
			it=mp.find(str1);
			if(it!=mp.end()) {
				it->second.pb(str2);
			}
			else {
				mp.insert(pair<string,vector<string> > (str1,{str2}));
			}
			it=mp.find(str2);
			if(it!=mp.end()) {
				it->second.pb(str1);
			}
			else {
				mp.insert(pair<string,vector<string> > (str2,{str1}));
			}
		}
		// bfs
		for(map<string,int>::iterator it=vis.begin();it!=vis.end();++it) {
			
		}
	}
	return 0;
}