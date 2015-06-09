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
int merge(int *arr,int p,int q,int mid) {
	var(int);
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
		//copy q
		while(j<=q) {
			tarr[tmp]=arr[j];
			j++;
			tmp++;
		}
	}
	else {
		//copy p
		while(i<=mid) {
			tarr[tmp]=arr[i];
			i++;
			tmp++;
		}
	}
	//copy tarr to arr
	fr(i,p,q+1) {
		arr[i]=tarr[i-p];
	}
	return tmp3;
}
int mergesort(int *arr,int p,int q) {
	var(int);
	tmp=p+q;tmp=tmp/2;
	tmp3=0;
	if(p<tmp) {
		tmp3=mergesort(arr,p,tmp);
		//pf("tt%dtt",tmp3);
	}
	if(tmp+1<q) {
		tmp3+=mergesort(arr,tmp+1,q);
		//pf("tt%dtt",tmp3);
	}
	tmp3+=merge(arr,p,q,tmp);
	//pf("tt%dtt",tmp3);
	return tmp3;
}
int main() {
	int arr[1000];
	var(int);
	int N,T;
	sc("%d",&N);
	fr(i,0,N) {
		sc("%d",&arr[i]);
	}
	pf("%d",mergesort(arr,0,N-1));
	pf("\n");
	//fr(i,0,N)
		//pf("%d ",arr[i]);
	return 0;
}