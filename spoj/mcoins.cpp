#include <cstdio>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1=0,tmp2=0,tmp3=0,tmp=0,tmp4=0,tmp5=0,flag=0
#define pb push_back
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
using namespace std;

int main() {
	var(int);
	int K,L,M;
	sc("%d %d %d",&K,&L,&M);
	bool arr[1000001]={false};
	fr(j,1,1000001) {
		if(j==1 || j==K || j==L) arr[j]=true;
		else if(arr[j-1]==false) arr[j]=true;
		else if(j>K && arr[j-K]==false) arr[j]=true;
		else if(j>L && arr[j-L]==false) arr[j]=true;
		else arr[j]=false;
	}
	fr(i,0,M) {
		sc("%d",&tmp);
		if(arr[tmp]) pf("A");
		else pf("B");
	}
	return 0;
}