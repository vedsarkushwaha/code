#include<bits/stdc++.h>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1=0,tmp2=0,tmp3=0,tmp=0,tmp4=0,tmp5=0,flag=0,T=0,M=0,N=0,K=0
#define pb push_back
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
#define sz 16
using namespace std;
ll md,dm;
struct mat {
	ll arr[20][20];
};
mat operator*(mat x,mat y) {
	var(ll);
	mat z;
	fr(i,0,dm) {
		fr(j,0,dm) {
			tmp=0;
			fr(k,0,dm) {
				tmp=(tmp+(x.arr[i][k]*y.arr[k][j]))%md;
			}
			z.arr[i][j]=tmp%md;
		}
	}
	return z;
}
mat power(mat x,ll y) {
	var(ll);
	mat z;
	fr(i,0,dm) {
		fr(j,0,dm) {
			if(i==j)
				z.arr[i][j]=1;
			else
				z.arr[i][j]=0;
		}
	}
	if(y==0)
		return z;
	else if(y==1)
		return x;
	else {
		z=power(x,y/2);
		if(y%2==0) {
			return z*z;
		}
		else {
			return z*z*x;
		}
	}
}
void prnt(mat x) {
	var(ll);
	fr(i,0,dm) {
		fr(j,0,dm) {
			pf("%lld ",x.arr[i][j]);
		}
		pf("\n");
	}
}
int main() {
	var(ll);
	sc("%lld",&T);
	while(T--) {
		sc("%lld",&K);
		dm=K+1;
		ll b[K],sm[K];
		fr(i,0,K) {
			sc("%lld",&b[i]);
			if(i==0)
				sm[i]=b[i];
			else
				sm[i]=sm[i-1]+b[i];
		}
		//fr(i,0,K) {
		//	pf("%lld %lld\n",b[i],sm[i]);
		//}
		mat mt;
		fr(i,0,dm) {
			fr(j,0,dm) {
				if(i==0) {
					if(j<2)
						mt.arr[i][j]=1;
					else
						mt.arr[i][j]=0;
				}
				else if(i==1) {
					if(j==0)
						mt.arr[i][j]=0;
					else
						sc("%lld",&mt.arr[i][j]);
				}
				else {
					if(i-1==j)
						mt.arr[i][j]=1;
					else
						mt.arr[i][j]=0;
				}
			}
		}
		ll m,n;
		sc("%lld %lld %lld",&m,&n,&md);
		if(m>K) {
			mat mt1=power(mt,m-K);
			//prnt(mt1);
			//pf("\n");
			if(K>=2)
				tmp4=mt1.arr[0][0]*sm[K-2];
			else
				tmp4=0;
			fr(i,0,K) {
				tmp4=(tmp4+b[K-i-1]*mt1.arr[0][i+1])%md;
			}
		}
		else if(m==1)
			tmp4=0;
		else
			tmp4=sm[m-2];
		if(n>K) {
			mat mt2=power(mt,n-K+1);
			if(K>=2)
				tmp5=mt2.arr[0][0]*sm[K-2];
			else
				tmp5=0;
			//prnt(mt2);
			//pf("\n");
			fr(i,0,K) {
				tmp5=(tmp5+b[K-i-1]*mt2.arr[0][i+1])%md;
			}
		}
		else
			tmp5=sm[n-1];
		//pf("%lld %lld\n",tmp5,tmp4);
		pf("%lld\n",(tmp5-tmp4+md)%md);
	}
	return 0;
}