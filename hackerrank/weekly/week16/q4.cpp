#include<bits/stdc++.h>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1=0,tmp2=0,tmp3=0,tmp=0,tmp4=0,tmp5=0,flag=0,T=0,N=0,Q=0,M=0
#define pb push_back
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vl vector<ll>
#define vll vector<pair<ll,ll> >

#define md 1000000007
using namespace std;

int main() {
	var(int);
	sc("%d %d",&N,&M);
	string inp[N];
	ll cnt=0;
	fr(i,0,N) cin>>inp[i];
	string req;
	cin>>req;
	vector<string> vec;
	// string filter
	fr(i,0,N) {
		flag=0;
		fr(j,0,M) {
			if(req[j]=='0' && inp[i][j]=='1') {
				flag=1;
				break;
			}
		}
		if(!flag) vec.pb(inp[i]);
	}
	// string filter over
	
	string arr;
	fr(i,1,1<<vec.size()) {
		arr.clear();
		fr(k,0,M) arr=arr+' ';
		fr(j,0,vec.size()) {
			if(i&(1<<j)) {
				fr(k,0,M) if(arr[k]!='1') arr[k]=inp[j][k];
			}
		}
		// pf("%d ",i);
		// cout<<arr<<endl;
		if(arr==req) cnt=(cnt+1)%md;
	}
	pf("%lld\n",cnt);
	return 0;
}