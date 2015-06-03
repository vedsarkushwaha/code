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
	int N;
	sc("%d",&N);
	char ch[N][N];
	tmp3=1;
	fr(i,0,N/2) {
		fr(j,0,N) {
			ch[i][j]=tmp3;
			//pf("%d ",tmp3);
			tmp3++;
		}
		fr(j,0,N) {
			//pf("%d ",tmp3);
			ch[N-i-1][j]=tmp3;
			tmp3++;
		}
	}
	if(N%2!=0) {
		fr(j,0,N) {
			//pf("%d ",tmp3);
			ch[N/2][j]=tmp3++;
		}
	}
	fr(i,0,N) {
		fr(j,0,N) {
			if(j==N-1)
				pf("%d",ch[i][j]);
			else
				pf("%d*",ch[i][j]);
		}
		pf("\n");
	}
	return 0;
}
