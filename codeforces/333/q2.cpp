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
	int n;
	sc("%d",&n);
	vi vec;
	fr(i,0,n) {
		sc("%d",&tmp);
		vec.pb(tmp);
	}
	int minVal,maxVal, minIndex,lRange,gRange;
	priority_queue<pair<int,int> , vii, greater<int> > pq;
	tmp=vec[0];
	minVal=tmp,maxVal=tmp,minIndex=0,lRange=0,gRange=0;
	pq.push(make_pair(minVal,0));
	i=0;
	pair<int,int> pr;
	fr(k,1,n) {
		tmp=vec[k];
		if(tmp<=minVal) {
			minVal=tmp;
			minIndex=k;
			pq.push(make_pair(minVal,k));
		}
		if(tmp>maxVal) {
			maxVal=tmp;
		}
		if(maxVal-minVal>1) {
			gRange=max(gRange,k-i);
			i=minIndex+1;
			minVal=vec[i];
		}
	}
	gRange=max(gRange,k-i);
	pf("%d",gRange);
	return 0;
}