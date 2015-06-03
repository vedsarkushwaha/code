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
struct mat {
	ll a,b,c,d;
};
ll md=1000000007;
mat operator*(mat a,mat b) {
	mat tmp;
	tmp.a=(a.a*b.a+a.b*b.c)%md;
	tmp.b=(a.a*b.b+a.b*b.d)%md;
	tmp.c=(a.c*b.a+a.d*b.c)%md;
	tmp.d=(a.c*b.b+a.d*b.d)%md;
	return tmp;
}
mat power(mat x,ll y) {
	mat temp;
	if(y==0) {
		temp.a=1,temp.b=0,temp.c=0,temp.d=1;
		return temp;
	}
	temp=power(x, y/2);
	if (y%2 == 0)
		return temp*temp;
	else
		return x*temp*temp;
}
ll fab(ll num) {
	mat mat1;
	var(ll);
	mat1.a=1,mat1.b=1,mat1.c=1,mat1.d=0;
	if(num==0)
		return 0;
	if(num==1 || num==2)
		return 1;
	else {
		mat1=power(mat1,num-1);
		return mat1.a;
	}
}
int main() {
	var(ll);
	sc("%lld",&T);
	while(T--) {
		sc("%lld",&N);
		pf("%lld\n",(fab(2*N)*fab(2*N+1))%md);
	}
	return 0;
}