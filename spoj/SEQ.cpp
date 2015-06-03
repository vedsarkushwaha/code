#include<bits/stdc++.h>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1=0,tmp2=0,tmp3=0,tmp=0,tmp4=0,tmp5=0,flag=0,T=0,M=0,N=0
#define pb push_back
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
using namespace std;
ll md=1000000000;
void mat_multi(ll a[10][10],ll b[10][10],ll lm) {
	//matrix multiplication
	ll tmp_mat[10][10];
	var(ll);
	fr(i,0,lm) {
		fr(j,0,lm) {
			tmp=0;
			fr(k,0,lm) {
				tmp+=(a[i][k]*b[k][j])%md;
			}
			tmp_mat[i][j]=tmp%md;
		}
	}
	fr(i,0,lm)
		fr(j,0,lm)
			a[i][j]=tmp_mat[i][j];
}
void power(ll x[10][10],ll y,ll lm) {
	var(ll);
	ll post_mat[10][10];
	fr(i,0,lm)
		fr(j,0,lm)
			if(i==j)
				post_mat[i][j]=1;
			else
				post_mat[i][j]=0;
	//pf("%lld\n",y);
	while(y!=1) {
		/*pf("Before\n");
		fr(i,0,lm) {
			fr(j,0,lm) {
				pf("%lld ",x[i][j]);
			}
			pf("\n");
		}
		pf("\n");*/
		if(y%2)
			mat_multi(post_mat,x,lm);
		y/=2;
		mat_multi(x,x,lm);
		/*pf("After\n");
		fr(i,0,lm) {
			fr(j,0,lm) {
				pf("%lld ",x[i][j]);
			}
			pf("\n");
		}
		pf("\n");*/
	}
	mat_multi(x,post_mat,lm);
}
int main() {
	var(ll);
	sc("%lld",&T);
	vl _b,_a;
	ll mat[10][10];
	while(T--) {
		sc("%lld",&N);
		_a.clear(),_b.clear();
		fr(i,0,N) {
			sc("%lld",&tmp);
			_b.pb(tmp);
		}
		fr(i,0,N) {
			sc("%lld",&tmp);
			_a.pb(tmp);
		}
		sc("%lld",&M);
		fr(i,0,10)
			fr(j,0,10)
				mat[i][j]=0;
		fr(i,0,N) {
			fr(j,0,N) {
				if(i==0) {
					mat[i][j]=_a[j];
				}
				else {
					if(i-1==j)
						mat[i][j]=1;
					else
						mat[i][j]=0;
				}
			}
		}
		/*fr(i,0,N) {
			fr(j,0,N) {
				pf("%lld ",mat[i][j]);
			}
			pf("\n");
		}
		pf("\n");*/
		if(M<=N)
			pf("%lld\n",_b[M-1]);
		else {
			power(mat,M-N,N);
			/*fr(i,0,N) {
				fr(j,0,N) {
					pf("%lld ",mat[i][j]);
				}
				pf("\n");
			}
			pf("\n");*/
			tmp=0;
			fr(i,0,N) {
				tmp+=(mat[0][i]*_b[N-i-1])%md;
			}
			pf("%lld\n",tmp%md);
		}
	}
	return 0;
}