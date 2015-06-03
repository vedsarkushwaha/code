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
int prm[sz+1];
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
int main() {
	var(int);
	seive_fun();
	vi vec;
	sc("%d %d %d",&tmp1,&tmp2,&tmp);
	tmp5=sqrt(tmp2);
	fr(i,0,tmp5+1)
		if(prm[i]==0)
			vec.pb(i);
	fr(i,tmp1,tmp2+1) {
		tmp5=1;
		k=i;
		fr(j,0,vec.size()) {
			N=sqrt(k);
			if(vec[j]>N+1)
				break;
			tmp3=0;
			while(k%vec[j]==0) {
				k/=vec[j];
				tmp3++;
			}
			tmp5*=(tmp3+1);
		}
		//pf("%d %d\n",i,tmp5);
		if(k!=1)
			tmp5*=2;
		if(tmp5==tmp)
			tmp4++;
	}
	pf("%d\n",tmp4);
	return 0;
}