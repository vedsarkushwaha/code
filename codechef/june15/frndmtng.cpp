#include <bits/stdc++.h>
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
	double T1,T2,t1,t2,ar1,ar2;
	sc("%d",&T);
	while(T--) {
		sc("%lf %lf %lf %lf",&T1,&T2,&t1,&t2);
		if(t1>T2) t1=T2;
		if(t2>T1) t2=T1;
		// ar1
		if(T1-t2<=T2) ar1=0.5*(T1-t2)*(T1-t2);
		else ar1=(0.5*T2*T2)+T2*(T1-T2-t2);
		// ar3
		if(T1>=T2-t1) ar2=0.5*(T2-t1)*(T2-t1);
		else ar2=(0.5*T1*T1)+T1*(T2-T1-t1);
		if(T1==0 && T2==0)
			pf("1\n");
		else if(T1==0 || T2==0)
			pf("0\n");
		else
			pf("%lf\n",((T1*T2)-ar1-ar2)/(T1*T2));
	}
	return 0;
}