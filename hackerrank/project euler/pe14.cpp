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

ll arr[5000001];
ll start_seq(ll s) {
	ll seq,cnt=0;
	seq=s;
	while(1) {
		if(arr[seq]!=0)
			return cnt+arr[seq];
		if(seq%2==0) {
			seq=seq/2;
		}
		else {
			seq=3*seq+1;
		}
		cnt++;
	}
}

int main() {
	ll i,num,j,T,nm;
	ll cnt,max=0L;
	arr[1]=1;
	scanf("%lld",&T);
	while(T--) {
		scanf("%lld",&i);
		max=0;
		//printf("%d %d",i,j);
		for(num=1;num<=i;num++) {
			if(arr[num]==0) {
				cnt=start_seq(num);
				arr[num]=cnt;
				//printf("%lld %d\n",cnt,num);
			}
			else {
				cnt=arr[num];
			}
            j=num;
			if(max<=cnt) {
				//printf("max=%lld ",max);
				max=cnt;
				nm=j;
			}
		}
		printf("%lld\n",nm);
	}
	return 0;
}