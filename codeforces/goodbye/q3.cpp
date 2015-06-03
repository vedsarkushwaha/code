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
	var(int);
	vi we,da,sq;
	int arr[501]={0};
	sc("%d %d",&T,&N);
	we.pb(0);
	fr(i,0,T) {
		sc("%d",&tmp);
		we.pb(tmp);
	}
	fr(i,0,N) {
		sc("%d",&tmp);
		da.pb(tmp);
		if(arr[tmp]==0) {
			arr[tmp]=1;
			sq.pb(tmp);
		}
	}
	/*fr(i,0,sq.size()) {
		pf("%d ",sq[i]);
	}
	pf("\n");*/
	tmp3=0;
	fr(i,0,N) {
		/*fr(k,0,sq.size()) {
			pf("%d ",sq[k]);
		}*/
		//pf("\n");
		//tmp3=we[da[i]];
		tmp2=(find(sq.begin(),sq.end(),da[i])-sq.begin());
		//pf("%d\n",tmp2);
		//fflush(stdout);
		j=tmp2-1;
		while(j>=0) {
			tmp3+=we[sq[j]];
			j--;
		}
		tmp=sq[tmp2];
		sq.erase(sq.begin()+tmp2);
		sq.insert(sq.begin(),tmp);
		//pf("%d\n",tmp3);
	}
	pf("%d",tmp3);
	return 0;
}
