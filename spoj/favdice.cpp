#include<bits/stdc++.h>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1=0,tmp2=0,tmp3=0,tmp=0,tmp4=0,tmp5=0,flag=0,T=0,N=0
#define pb push_back
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
#define sz 10000
using namespace std;
double fun(double n) {
	var(double);
	fr(i,1,n+1) {
		tmp5+=(1.0/i);
	}
	return n*tmp5;
}
int main() {
	var(double);
	sc("%lf",&T);
	while(T--) {
		sc("%lf",&N);
		pf("%.2lf\n",fun(N));
	}
	return 0;
}