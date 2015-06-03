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
int main() {
	var(int);
	sc("%d",&T);
	while(T--) {
		sc("%d %d",&tmp1,&tmp2);
		if(tmp1<=tmp2) {
			if(tmp1%2)
				pf("R\n");
			else
				pf("L\n");
		}
		else {
			if(tmp2%2)
				pf("D\n");
			else
				pf("U\n");
		}
	}
	return 0;
}