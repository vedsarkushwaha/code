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
	pair<int,int> p1,p2;
	p1.first=10,p1.second=20;
	p2=p1;
	pf("%d %d\n",p1.first,p1.second);
	pf("%d %d\n",p2.first,p2.second);
	p1.first=20;
	pf("%d %d\n",p1.first,p1.second);
	pf("%d %d\n",p2.first,p2.second);
	return 0;
}