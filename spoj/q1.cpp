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
#define sz 100000
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
int prm[sz+1];
void init() {
	int i;
	for(i=0;i<=sz;i++)
		prm[i]=1;
	prm[0]=0;
	prm[1]=0;
}
void seive_fun() {
	int i,j,k,limit;
	//init();
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
unsigned ll gcd(unsigned ll a,unsigned ll b) {
  while (b != 0)  {
    unsigned ll t = b;
    b = a % b;
    a = t;
    //pf("gcd");
  }
  return a;
}
int main() {
	var(unsigned ll);
	int t;
	double avg;
	vector<int> vec;
	sc("%d",&t);
	seive_fun();
	fr(i,2,sz+1)
		if(prm[i]==0)
			vec.push_back(i);
	while(t--) {
		i=1;
		sc("%lf",&avg);
		while((unsigned ll)(avg)!=avg) {
			i*=10;
			avg*=10;
			//pf("ii");
		}
		tmp=(unsigned ll)avg;
		fr(j,0,vec.size()) {
			if(((vec[j]%tmp)==0) && (vec[j]%i==0)) {
				while(((vec[j]%tmp)==0) && (vec[j]%i==0)) {
					tmp=tmp/vec[j];
					i=i/vec[j];
				}
			}
		}
		pf("%llu\n",i);
	}
	return 0;
}
