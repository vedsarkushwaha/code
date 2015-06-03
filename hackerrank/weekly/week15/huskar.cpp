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
	int hus,tuk;
	sc("%d %d",&N,&Q);
	// pf("%d %d\n",N,Q);
	int par[N+1];
	fr(i,2,N+1) {
		sc("%d",&tmp);
		par[i]=tmp;
		// pf("%d\n",tmp);
	}
	while(Q--) {
		sc("%d %d",&hus,&tuk);
		// pf("%d %d\n",hus,tuk);
		int trav[N+1];
		fr(i,0,N+1) trav[i]=0;
		int husL=0,tukL=0;
		tmp=hus;
		tmp5=0;
		while(tmp!=1) {
			// pf("%d %d\n",tmp,hus);
			trav[tmp]=1;
			if(tmp==tuk) tmp5=husL;
			husL++;
			tmp=par[tmp];
		}
		trav[tmp]=1;
		if(tmp==tuk) tmp5=husL;
		husL++;
		// fflush(stdout);
		if(tmp5==0) {
			tmp=tuk;
			while(tmp!=1) {
				// pf("%d\n",tmp);
				if(trav[tmp]==1) break;
				tukL++;
				tmp=par[tmp];
			}
		}
		if(tmp5) {
			pf("%d %d\n",tmp5,husL-tmp5);
		}
		else {
			pf("%d %d\n",husL,tukL);
		}
	}
	return 0;
}