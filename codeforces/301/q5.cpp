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
ll merge(int *arr,int p,int q,int mid) {
	var(ll);
	int tarr[q-p+1];
	i=p;j=mid+1;
	tmp3=0;
	while(i<=mid && j<=q) {
		if(arr[i]>arr[j]) {
			tarr[tmp]=arr[j];
			j++;
			tmp3+=(mid-i+1);
		}
		else {
			tarr[tmp]=arr[i];
			i++;
		}
		tmp++;
	}
	if(i>mid) {
		while(j<=q) {
			tarr[tmp]=arr[j];
			j++;
			tmp++;
		}
	}
	else {
		while(i<=mid) {
			tarr[tmp]=arr[i];
			i++;
			tmp++;
		}
	}
	fr(i,p,q+1) {
		arr[i]=tarr[i-p];
	}
	return tmp3;
}
ll mergesort(int *arr,int p,int q) {
	var(ll);
	tmp=p+q;tmp=tmp/2;
	tmp3=0;
	if(p<tmp) {
		tmp3=mergesort(arr,p,tmp);
	}
	if(tmp+1<q) {
		tmp3+=mergesort(arr,tmp+1,q);
	}
	tmp3+=merge(arr,p,q,tmp);
	return tmp3;
}
int main() {
	var(int);
	vii vec;
	map<int,int> mp;
	sc("%d",&N);
	fr(i,0,N) {
		sc("%d %d",&tmp1,&tmp2);
		vec.pb(make_pair(tmp1,tmp2));
		if(mp.find(tmp1)!=mp.end()) {
			tmp3=mp[tmp1];
		}
		else {
			tmp3=tmp1;
		}
		if(mp.find(tmp2)!=mp.end()) {
			tmp4=mp[tmp2];
		}
		else {
			tmp4=tmp2;
		}
		mp[tmp1]=tmp4;
		mp[tmp2]=tmp3;
	}
	map<int,int>:: iterator it;
	int arr[mp.size()+1];
	arr[0]=-10;
	i=1;
	for(it=mp.begin();it!=mp.end();++it) {
		arr[i]=it->second;
		i++;
	}
	ll inversion_cnt=mergesort(arr,1,mp.size());
	sort(arr,arr+mp.size());
	for(it=mp.begin();it!=mp.end();++it) {
		tmp1=it->first;
		tmp2=it->second;
		inversion_cnt+=abs(tmp1-tmp2)-1;
		inversion_cnt-=abs(lower_bound(arr,arr+mp.size(),tmp1)-lower_bound(arr,arr+mp.size(),tmp2))-1;
	}
	pf("%lld\n",inversion_cnt);
	return 0;
}