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
	int E,_E,F,_F,S,_S,M,_M;
	while(1) {
		sc("%d %d %d %d %d %d %d %d",&E,&F,&S,&M,&_E,&_F,&_S,&_M);
		if(E==-1 && F==-1 && S==-1 && M==-1 &&_E==-1 && _F==-1 && _S==-1 &&_M==-1)
			break;
		if(E%_E==0)
			tmp=E/_E;
		else
			tmp=E/_E+1;
		if(F%_F==0)
			tmp=max(tmp,F/_F);
		else
			tmp=max(tmp,F/_F+1);
		if(S%_S==0)
			tmp=max(tmp,S/_S);
		else
			tmp=max(tmp,S/_S+1);
		if(M%_M==0)
			tmp=max(tmp,M/_M);
		else
			tmp=max(tmp,M/_M+1);

		pf("%d %d %d %d\n",tmp*_E-E,tmp*_F-F,tmp*_S-S,tmp*_M-M);
	}
	return 0;
}