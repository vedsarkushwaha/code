#include<bits/stdc++.h>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1=0,tmp2=0,tmp3=0,tmp=0,tmp4=0,tmp5=0,flag=0,T=0,N=0,M=0
#define pb push_back
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
using namespace std;

int main() {
	var(int);
	sc("%d %d",&N,&M);
	vi inp;
	fr(i,0,N) {
		sc("%d",&tmp);
		inp.pb(tmp);
	}
	tmp5=0,tmp4=0;
	i=0,j=0;
	while(i<N && j<N) {
		tmp4+=inp[j];
		while(tmp4>M) {tmp4-=inp[i];i++;}
		tmp5=max(tmp5,tmp4);
		j++;
		//pf("%d\n",tmp4);
	}
	pf("%d",tmp5);	
	return 0;
}
