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
#define var(x) x i=0,j=0,k=0,tmp1,tmp2,tmp3,tmp=0,T
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
int mod(int x) {
	if(x<0)
		return -x;
	else
		return x;
}
int main() {
	var(int);
	vector<int> vec;
	while(1) {
		sc("%d",&T);
		if(T==-1)
			break;
		tmp3=0;
		vec.clear();
		while(T--) {
			sc("%d",&tmp);
			tmp3+=tmp;
			vec.push_back(tmp);
		}
		if(tmp3%vec.size()==0) {
			tmp=tmp3/vec.size();
			tmp2=0;
			fr(i,0,vec.size())
				tmp2+=(mod(tmp-vec[i]));
			pf("%d\n",tmp2/2);
		}
		else
			pf("-1\n");
	}
	return 0;
}
