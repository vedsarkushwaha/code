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
	sc("%d",&N);
	int arr[1000000]={0};
	int L,H,ans=0;
	fr(i,0,N) {
		sc("%d %d",&L,&H);
		arr[L+1]++;
		arr[H+2]--;
		tmp=max(tmp,H+1);
	}
	fr(i,1,tmp+1) {
		arr[i]+=arr[i-1];
	}
	// fr(i,1,tmp+1) {
	// 	pf("%d ",arr[i]);
	// }
	fr(i,0,tmp+1) {
		if(i<=arr[i]) ans=i;
	}
	pf("%d",ans);
}