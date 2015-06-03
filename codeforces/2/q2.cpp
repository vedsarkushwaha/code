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
ll cntt(ll num) {
	var(ll);
	if(!num)
		return 0;
	while(num%2==0) {
		tmp++;
		num/=2;
	}
	return tmp;
}
ll cntf(ll num) {
	var(ll);
	if(!num)
		return 0;
	while(num%5==0) {
		tmp++;
		num/=5;
	}
	return tmp;
}
int main() {
	var(ll);
	sc("%lld",&N);
	tmp5=INT_MAX;
	pair<ll,ll> pr[N+2][N+2];
	fr(i,1,N+1) {
		fr(j,1,N+1) {
			sc("%lld",&tmp);
			if(tmp==0) {
				tmp5=1;
				tmp3=i;
				tmp2=j;
			}
			pr[i][j].first=cntt(tmp);
			pr[i][j].second=cntf(tmp);
		}
	}
	ll dpt[N+2][N+2],dpf[N+2][N+2];
	string patht,pathf;
	fr(i,0,N+1) {
		fr(j,0,N+1) {
			if(i==0 || j==0) {
				dpt[i][j]=INT_MAX;
				dpf[i][j]=INT_MAX;
			}
			else if(i==1 && j==1) {
				dpt[i][j]=pr[i][j].first;
				dpf[i][j]=pr[i][j].second;
			}
			else {
				dpt[i][j]=min(dpt[i-1][j],dpt[i][j-1])+pr[i][j].first;
				dpf[i][j]=min(dpf[i-1][j],dpf[i][j-1])+pr[i][j].second;
			}
		}
	}
	tmp4=min(dpt[N][N],dpf[N][N]);
	if(tmp4>tmp5) {
		pf("%lld\n",tmp5);
		//print zero path
		i=1,j=1;
		while(i!=tmp3) {
			pf("D");
			i++;
		}
		while(j!=tmp2) {
			pf("R");
			j++;
		}
		while(tmp3!=N) {
			pf("D");
			tmp3++;
		}
		while(tmp2!=N) {
			pf("R");
			tmp2++;
		}
	}
	else if(dpt[N][N]<dpf[N][N]) {
		pf("%lld\n",dpt[N][N]);
		i=N,j=N;
		while(i!=1 && j!=1) {
			if(dpt[i-1][j]<dpt[i][j-1]) {
				patht+='D';
				i--;
			}
			else {
				patht+='R';
				j--;
			}
		}
		if(i==1) {
			while(j!=1) {
				patht+='R';
				j--;
			}
		}
		else {
			while(i!=1) {
				patht+='D';
				i--;
			}	
		}
		//pront two path
		reverse(patht.begin(),patht.end());
		cout<<patht;
	}
	else {
		pf("%lld\n",dpf[N][N]);
		//pront five path
		i=N,j=N;
		while(i!=1 && j!=1) {
			if(dpf[i-1][j]<dpf[i][j-1]) {
				pathf+='D';
				i--;
			}
			else {
				pathf+='R';
				j--;
			}
		}
		if(i==1) {
			while(j!=1) {
				pathf+='R';
				j--;
			}
		}
		else {
			while(i!=1) {
				pathf+='D';
				i--;
			}	
		}
		reverse(pathf.begin(),pathf.end());
		cout<<pathf;
	}
	// pf("\n");
	// fr(i,1,N+1) {
	// 	fr(j,1,N+1) {
	// 		pf("%lld ",dpt[i][j]);
	// 	}
	// 	pf("\n");
	// }
	// pf("\n");
	// fr(i,1,N+1) {
	// 	fr(j,1,N+1) {
	// 		pf("%lld ",dpf[i][j]);
	// 	}
	// 	pf("\n");
	// }
	return 0;
}