#include <cstdio>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1=0,tmp2=0,tmp3=0,tmp=0,tmp4=0,tmp5=0,flag=0

using namespace std;

int main() {
	var(int);
	int N;
	sc("%d",&N);
	int arr[100001]={0};
	fr(i,1,N+1) {
		sc("%d",&tmp);
		arr[tmp]=1;
	}
	fr(i,1,N+1) {
		if(!arr[i]) pf("%d ",i);
	}
	return 0;
}