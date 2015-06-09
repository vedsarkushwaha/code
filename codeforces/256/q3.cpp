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
int arr[5001];
int fun(int l,int r) {
	var(int);
	int cnt=0;
	tmp=*min_element(arr+l,arr+r);
	if(tmp!=0) {
		fr(i,l,r) arr[i]-=tmp;
		cnt+=tmp;
	}
	j=l;
	fr(i,l,r) {
		if(arr[i]==0) {
			cnt+=fun(j,i);
			j=i+1;
		}
	}
	if(i!=j) cnt+=fun(j,i);
	return min(cnt,r-l);
}
int main() {
	var(int);
	sc("%d",&N);
	fr(i,0,N) {
		sc("%d",&tmp);
		arr[i]=tmp;
	}
	pf("%d",fun(0,N));
	return 0;
}