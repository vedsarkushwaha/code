#include<cstdio>
#include<iostream>
#include<vector>
#include<stack>
#include<map>
#include<set>
#include<cstring>
#include<cmath>
#include<string>
#include<cstdlib>
#include<queue>
#include<algorithm>
#include<climits>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1=0,tmp2=0,tmp3=0,tmp=0,tmp4=0,tmp5=0,flag=0,T=0,N=0
#define pb push_back
#define vi vector<int>
#define vii pair<int,int>
#define vl vector<ll>
#define vll vector<ll,ll>
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
	vi vec;
	sc("%d",&T);
	while(T--) {
		vec.clear();
		sc("%d %d",&N,&k);
		fr(i,0,N) {
			sc("%d",&tmp);
			vec.pb(tmp);
		}
		sort(vec.begin(),vec.end());
		tmp3=INT_MAX;
		fr(i,0,N-k+1) {
			if(tmp3>(vec[i+k-1]-vec[i]))
				tmp3=vec[i+k-1]-vec[i];
		}
		pf("%d\n",tmp3);
	}
	return 0;
}