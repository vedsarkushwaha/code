#include<bits/stdc++.h>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1=0,tmp2=0,tmp3=0,tmp=0,tmp4=0,tmp5=0,flag=0,T=0,N=0
#define pb push_back
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
using namespace std;

int main() {
	var(int);
	sc("%d",&T);
	vi vec;
	int arr[10000]={0};
	while(T--) {
		sc("%d",&tmp);
		sc("%d",&N);
		vec.pb(tmp);
		while(N--) {
			sc("%d",&tmp);
			arr[tmp]=1;
		}
	}
	fr(i,0,vec.size())
		arr[vec[i]]=0;
	fr(i,0,10000) {
		if(arr[i]==1) {
			arr[i]=0;
			tmp5++;
		}
	}
	pf("%d",tmp5);
	return 0;
}