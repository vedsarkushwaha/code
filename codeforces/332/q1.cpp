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
	int d1,d2,d3;
	sc("%d %d %d",&d1,&d2,&d3);
	tmp=d1;
	if(d1+d2>d3) tmp+=(d3);
	else tmp+=(d1+d2);
	if(d1+d3>d2) tmp+=d2;
	else tmp+=(d1+d3);


	tmp2=d2;
	if(d1+d2>d3) tmp2+=(d3);
	else tmp2+=(d1+d2);
	if(d2+d3>d1) tmp2+=d1;
	else tmp2+=(d2+d3);
	pf("%d",min(tmp2,tmp));
	return 0;
}