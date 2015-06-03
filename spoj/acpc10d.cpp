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
	
	while(1) {
		tmp5++;
		sc("%d",&N);
		int arr[N][3];
		if(N==0)
			break;
		fr(i,0,N) {
			sc("%d %d %d",&arr[i][0],&arr[i][1],&arr[i][2]);
		}
		arr[1][0]+=arr[0][1];
		arr[0][2]+=arr[0][1];
		arr[1][1]+=min(min(arr[0][1],arr[0][2]),arr[1][0]);
		arr[1][2]+=min(min(arr[0][1],arr[0][2]),arr[1][1]);
		fr(i,2,N) {
			arr[i][0]+=min(arr[i-1][0],arr[i-1][1]);
			arr[i][1]+=min(min(arr[i-1][1],arr[i-1][2]),min(arr[i][0],arr[i-1][0]));
			arr[i][2]+=min(min(arr[i-1][2],arr[i-1][1]),arr[i][1]);
		}
		/*fr(i,0,N) {
			pf("%d %d %d\n",arr[i][0],arr[i][1],arr[i][2]);
		}*/
		pf("%d. %d\n",tmp5,arr[N-1][1]);
	}
	return 0;
}