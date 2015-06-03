#include <bits/stdc++.h>
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
#define sz 1000000
using namespace std;
bool prm[sz+1];
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
int power(int x,int y) {
	int temp;
	if(y==0)
		return 1;
	temp=power(x, y/2);
	if (y%2 == 0)
		return temp*temp;
	else
		return x*temp*temp;
}
int pali(int a,int b) {
	var(int);
	int arr1[10]={0},arr2[10]={0};
	while(a!=0) {
		arr1[a%10]+=1;
		a=a/10;
	}
	while(b!=0) {
		arr2[b%10]+=1;
		b=b/10;
	}
	fr(i,0,10) {
		if(arr1[i]!=arr2[i])
			return 0;
	}
	return 1;
}
int main() {
	seive_fun();
	var(int);
	vi vec;
	pf("vector<pair<int, int>> myVec = {");
	fr(i,0,sz+1) {
		if(prm[i]==0)
			vec.pb(i);
	}
	tmp3=10000001;
	fr(j,1,tmp3) {
		//factorize
		vii ft;
		N=j;
		tmp=sqrt(N);
		fr(i,2,tmp+1) {
			if(N%i==0) {
				tmp1=0;
				while(N%i==0) {
					tmp1++;
					N=N/i;
				}
				ft.pb(make_pair(i,tmp1));
			}
		}
		if(N!=1)
			ft.pb(make_pair(N,1));
		tmp5=1;
		fr(i,0,ft.size()) {
			tmp4=power(ft[i].first,ft[i].second);
			tmp5*=(tmp4-tmp4/ft[i].first);
		}
		if(j>87109)
			break;
		pf("%d ",tmp5);
		if(pali(j,tmp5)) {
			pf("{%d,%d},",j,tmp5);
		}
	}
	pf("}");
	return 0;
}