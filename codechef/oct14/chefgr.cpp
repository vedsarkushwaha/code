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
#define fr(i,m,n) for(i=m;i<n;i++)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1,tmp2,tmp3,tmp=0
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
	int T,N,M;
	float qq;
	vector<int> vec;
	sc("%d",&T);
	while(T--) {
		tmp3=0;
		tmp2=0;
		vec.clear();
		sc("%d %d",&N,&M);
		fr(i,0,N) {
			sc("%d",&tmp);
			if(tmp3<tmp)
				tmp3=tmp;
			vec.push_back(tmp);
		}
		fr(i,0,vec.size())
			tmp2+=(tmp3-vec.at(i));
		if(M<tmp2)
			pf("No\n");
		else {
			if((M-tmp2)%N==0)
				pf("Yes\n");
			else
				pf("No\n");
		}
	}
	return 0;
}
