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
	string s,t;
	var(int);
	cin>>s>>t;
	if(s.find(t)!=string::npos) {
		pf("automaton\n");
		return 0;
	}
	tmp=-1;
	fr(i,0,t.size()) {
		tmp=s.find(t[i],tmp+1);
		if(tmp==string::npos) {
			tmp1=1;
			break;
		}
	}
	if(!tmp1) {
		pf("automaton\n");
		return 0;
	}
	int arr[26]={0};
	fr(i,0,s.size()) arr[s[i]-'a']+=1;
	fr(i,0,t.size()) {
		arr[t[i]-'a']-=1;
		if(arr[t[i]-'a']<0) {
			pf("need tree\n");
			return 0;
		}
	}
	if(s.size()==t.size()) pf("array\n");
	else pf("both\n");
	return 0;
}