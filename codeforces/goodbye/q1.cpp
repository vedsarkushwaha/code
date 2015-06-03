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
#define var(x) x i=0,j=0,k=0,tmp1,tmp2,tmp3,tmp=0,T,N
#define pb push_back
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<pii>
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
	vi vec;
	var(int);
	sc("%d %d",&N,&T);
	vec.pb(0);
	fr(i,1,N) {
		sc("%d",&tmp);
		vec.pb(tmp);
	}
	i=1;
	while(i<N) {
		if(i==T) {
			pf("YES\n");
			return 0;
		}
		i=vec[i]+(i);
	}
	pf("NO");
	return 0;
}
