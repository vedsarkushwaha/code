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
void init(double arr[401][401]) {
	int i,j;
	fr(i,0,401)
		fr(j,0,401)
			arr[i][j]=0;
}
int main() {
	int T,W,L,B;
	var(int);
	sc("%d",&T);
	double arr[401][401];
	while(T--) {
		sc("%d %d %d",&W,&L,&B);
		init(arr);
		arr[1][1]=W;
		fr(i,1,L) {
			fr(j,1,i+1) {
				if(arr[i][j]>1) {
					arr[i+1][j]+=(arr[i][j]-1)/2;
					arr[i+1][j+1]+=(arr[i][j]-1)/2;
					arr[i][j]=1;
				}
			}
		}
		pf("%lf\n",arr[i][B]);
	}
	return 0;
}
