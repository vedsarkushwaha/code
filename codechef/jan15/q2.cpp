#include<bits/stdc++.h>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1=0,tmp2=0,tmp3=0,tmp=0,tmp4=0,tmp5=0,flag=0,T=0,N=0,Q=0
#define pb push_back
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
using namespace std;
int gcd(int a,int b) {
  while (b != 0)  {
    int t = b;
    b = a % b;
    a = t;
  }
  return a;
}
int main() {
	var(int);
	sc("%d",&T);
	while(T--) {
		sc("%d %d",&N,&Q);
		int inp[N+1],lft[N+1],rgt[N+1];
		fr(i,1,N+1) {
			sc("%d",&tmp);
			inp[i]=tmp;
			if(i!=1)
				lft[i]=gcd(lft[i-1],tmp);
			else
				lft[i]=tmp;
		}
		rgt[N]=tmp;
		ifr(i,N-1,0)
			rgt[i]=gcd(rgt[i+1],inp[i]);
		while(Q--) {
			sc("%d %d",&tmp4,&tmp5);
			if(tmp4==1) {
				pf("%d\n",rgt[tmp5+1]);
			}
			else if(tmp5==N) {
				pf("%d\n",lft[tmp4-1]);
			}
			else {
				pf("%d\n",gcd(rgt[tmp5+1],lft[tmp4-1]));
			}
		}
	}
	return 0;
}
