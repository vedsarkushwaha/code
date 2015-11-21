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
	int zero,one;
	vi vec;
	sc("%d %d",&zero,&one);
	while(zero>0 || one>0) {
		if(zero>=one && tmp==0) {
			vec.pb(0);
			tmp1=0;
			tmp=1;
			zero--;
		}
		else if(one>zero && tmp1<2) {
			vec.pb(1);
			tmp1++;
			one--;
			tmp=0;
		}
		else if(one>zero && tmp1==2 && zero!=0) {
			vec.pb(0);
			tmp1=0;
			zero--;
			tmp=1;
		}
		else if(zero>=one && tmp==1 && one!=0) {
			vec.pb(1);
			tmp=0;
			one--;
			tmp1++;
		}
		else {
			pf("-1");
			return 0;
		}
	}
	fr(i,0,vec.size()) pf("%d",vec[i]);
	return 0;
}
