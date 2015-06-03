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
#define sz 10000
using namespace std;
int prm[sz+1];
int prmct[10000001];
void seive_fun() {
	int i,j,k,limit;
	prm[0]=1;
	prm[1]=1;
	limit=sqrt(sz);
	for(i=2;i<=limit;i++) {
		if(prm[i]==0) {
			k=sz/i;
			for(j=2;j<=k;j++)
				prm[i*j]=1;
		}
	}
}
int calc(int num) {
	var(int);
	tmp=num;
	tmp5=sqrt(num)+1;
	tmp4=0;
	fr(i,2,tmp5+1) {
		if(prm[i]==0) {
			if(num%i==0) {
				tmp4++;
				while(num%i==0) {num=num/i;}
			}
		}
	}
	if(num!=1)
		tmp4++;
	return tmp4;
}
int main() {
	var(int);
	seive_fun();
	sc("%d",&T);
	fr(i,1,T+1) {
		sc("%d %d %d",&tmp2,&tmp3,&tmp4);
		tmp=0;
		fr(j,tmp2,tmp3+1) {
			if(prmct[j]==0)
				prmct[j]=calc(j);
			if(prmct[j]==tmp4)
				tmp++;
		}
		pf("Case #%d: %d\n",i,tmp);
	}
	return 0;
}
