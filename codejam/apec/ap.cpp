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
struct node {
	vector<int> sv;
	int val;
};
int g_mx;
int flag;
node dp[111][111];
int chk_vec(vector<int> a,vector<int> b) {
	len=min(a.size(),b.size());
	var(int);
	fr(i,0,len) {
		if((a[i]==-1)&&(b[i]==-1))
			return 1;
		if(a[i]!=b[i])
			return 0;
	}
	return 1;
}
void solve(vector<int> vec,int K,int mx) {
	var(int);
	vector<int>::iterator it;
	for(it=vec.begin();(it!=vec.end()-2)&&(*it!=-1);++it) {
		if(flag==1)
			break;
		if(((*(it+1)-(*(it)))==K)&&((*(it+2)-(*(it+1)))==K)) {
			vec.erase(it,it+3);
			//pf("%d\n",mx);
			solve(vec,K,mx+1);
			//pf("%d\n",tmp);
		}
	}
	if(g_mx<mx)
		g_mx=mx;
	if(vec.size()<7)
		flag=1;
}
int main() {
	var(int);
	int T,N,K;
	vector<int> vec;
	sc("%d",&T);
	fr(i,1,T+1) {
		sc("%d %d",&N,&K);
		fr(j,0,N) {
			sc("%d",&tmp);
			vec.push_back(tmp);
		}
		vec.push_back(-1);vec.push_back(-1);vec.push_back(-1);vec.push_back(-1);
		g_mx=0;flag=0;
		solve(vec,K,0);
		pf("%d\n",N-3*g_mx);
		vec.clear();
	}
	return 0;
}
