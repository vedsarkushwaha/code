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
	string str;
	var(ll);
	vii vec;
	cin>>str;
	fr(i,0,str.length()) {
		if((str[i]-'0')%2==0) {
			vec.pb(make_pair((str[i]-'0'),i));
		}
	}
	if(vec.size()==0) {
		pf("-1");
		return 0;
	}
	else if(vec.size()==1) {
		swap(str[vec[0].second],str[str.length()-1]);
		cout<<str;
		return 0;
	}
	//sort(vec.begin(),vec.end());
	fr(i,0,str.length()) {
		if((str[i]-'0')%2==0)
			//pf(" %d yes\n",i);
			tmp=i;
		if((str[i]<str[str.length()-1]) && ((str[i]-'0')%2==0)) {
			//pf("  %lld   ",tmp);
			swap(str[i],str[str.length()-1]);
			cout<<str<<endl;
			return 0;
		}
	}
	swap(str[tmp],str[str.length()-1]);
	cout<<str;
	return 0;
}
