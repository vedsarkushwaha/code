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
void init(double *arr) {
	int i;
	fr(i,0,160000)
		arr[i]=0;
}
void print(double *arr) {
	int i;
	fr(i,0,10)
		pf("%.3lf ",arr[i]);
	pf("\n");
}
int main() {
	double arr[160000],arr2[160000],wtr;
	var(int);
	int T,B,L,N;
	sc("%d",&T);
	fr(tmp,1,T+1) {
		sc("%d %d %d",&B,&L,&N);
		init(arr);
		init(arr2);
		wtr=double(B*750);
		arr[1]=wtr;//arr2[1]=wtr;
		fr(i,1,L+1) {
			tmp1=0;
			fr(j,1,i+1) {
				fr(k,0,j) {
					tmp1++;
					if(arr[tmp1]>250.0) {
						arr2[tmp1]+=(arr[tmp1]-250.0)/3;
						arr2[tmp1+j]+=(arr[tmp1]-250.0)/3;
						arr2[tmp1+j+1]+=(arr[tmp1]-250.0)/3;
						arr[tmp1]=250.0;
					}
				}
			}
			//print(arr);
			//print(arr2);
			//copy
			if(i!=L)
			fr(j,1,160000) {
				arr[j]=arr2[j];
				arr2[j]=0;
			}
		}
		pf("Case #%d: %0.7lf\n",tmp,arr[N]);
	}
	return 0;
}
