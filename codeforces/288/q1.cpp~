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
unsigned ll power(unsigned ll x,unsigned ll y) {
	unsigned ll temp;
	if(y==0)
		return 1;
	temp=power(x, y/2);
	if (y%2 == 0)
		return temp*temp;
	else
		return x*temp*temp;
}
unsigned ll gcd(unsigned ll a, unsigned ll b) {
  while (b != 0)  {
    int t = b;
    b = a % b;
    a = t;
  }
  return a;
}
int main() {
	var(int);
	int M;
	sc("%d %d",&N,&M);
	int arr[N+10][M+10];
	fr(i,0,N+10) {
		fr(j,0,M+10) {
			arr[i][j]=0;
		}
	}
	sc("%d",&T);
	fr(i,0,T) {
		sc("%d %d",&tmp1,&tmp2);
		if((arr[tmp1-1][tmp2-1]==1 && arr[tmp1-1][tmp2]==1 && arr[tmp1][tmp2-1]==1)||(arr[tmp1-1][tmp2]==1 && arr[tmp1-1][tmp2+1]==1 && arr[tmp1][tmp2+1]==1)||(arr[tmp1][tmp2+1]==1 && arr[tmp1+1][tmp2]==1 && arr[tmp1+1][tmp2+1]==1)||(arr[tmp1][tmp2-1]==1 && arr[tmp1+1][tmp2-1]==1 && arr[tmp1+1][tmp2]==1)) {
			pf("%d",i+1);
			tmp5=1;
			break;
		}
		else
			arr[tmp1][tmp2]=1;
	}
	if(tmp5==0)
		pf("0");
	return 0;
}
