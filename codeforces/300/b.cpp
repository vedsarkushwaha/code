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
int getLargest(int num) {
	var(int);
	vi str;
	while(num!=0) {
		tmp1=num%10;
		num/=10;
		str.pb(tmp1);
	}
	reverse(str.begin(),str.end());
	fr(i,0,str.size()) {
		if(str[i]>=1)
			tmp=((tmp*10)+1);
		else
			tmp=(tmp*10);
	}
	return tmp;
}
int main() {
	var(int);
	sc("%d",&N);
	vi vec;
	while(N) {
		tmp=getLargest(N);
		// pf("%d ",tmp);

		vec.pb(tmp);
		// if(tmp==0)
			// break;
		N-=tmp;
	}
	pf("%d\n",vec.size());
	fr(i,0,vec.size()) {
		pf("%d ",vec[i]);
	}
	return 0;
}