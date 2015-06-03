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

int main() {
	var(int);
	int n,m,q;
	sc("%d %d %d",&n,&m,&q);
	int arr[n+2][m+2],mx[n+2];
	fr(i,1,n+1) {
		mx[i]=0;
		fr(j,1,m+1) {
			sc("%d",&arr[i][j]);
		}
	}
	fr(i,1,n+1) {
		tmp=0;
		fr(j,1,m+1) {
			if(arr[i][j]) {
				tmp++;
			}
			else {
				mx[i]=max(mx[i],tmp);
				tmp=0;
			}
		}
		mx[i]=max(mx[i],tmp);
	}
	fr(i,1,q+1) {
		sc("%d %d",&tmp1,&tmp2);
		int cnt=0;
		arr[tmp1][tmp2]=1-arr[tmp1][tmp2];
		mx[tmp1]=0;
		fr(j,1,m+1) {
			if(arr[tmp1][j]) {
				cnt++;
			}
			else {
				mx[tmp1]=max(mx[tmp1],cnt);
				cnt=0;
			}
		}
		mx[tmp1]=max(mx[tmp1],cnt);
		pf("%d\n",*max_element(mx+1,mx+n+1));
	}
	return 0;
}