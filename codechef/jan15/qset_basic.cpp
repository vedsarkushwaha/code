#include<bits/stdc++.h>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1=0,tmp2=0,tmp3=0,tmp=0,tmp4=0,tmp5=0,flag=0,T=0,Q=0
#define pb push_back
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
using namespace std;

void print(vi &vec) {
	var(int);
	fr(i,1,vec.size()) pf("%d ",vec[i]);
}
int main() {
	var(int);
	int n,m;
	vi vec;
	char ch;
	sc("%d %d\n",&n,&m);
	vec.pb(0);
	fr(i,1,n+1) {
		sc("%c",&ch);
		// pf("%c\n",ch);
		tmp=ch-'0';
		if(i==1) vec.pb(tmp%3);
		else {
			vec.pb((vec.back()+tmp)%3);
		}
	}
	// print(vec);pf("\n");
	sc("%c",&ch);
	fr(i,0,m) {
		int opr,x,y;
		sc("%d %d %d",&opr,&x,&y);
		int cnt1=0,cnt2=0,cnt0=0;
		if(opr==2) {
			fr(j,x,y+1) {
				if(vec[j]==0) cnt0++;
				else if(vec[j]==1) cnt1++;
				else if(vec[j]==2) cnt2++;
			}
			int total=0;
			total=(cnt0*(cnt0-1))/2 + (cnt1*(cnt1-1))/2 + (cnt2*(cnt2-1))/2;
			if(vec[x-1]==0) total+=cnt0;
			else if(vec[x-1]==1) total+=cnt1;
			else if(vec[x-1]==2) total+=cnt2;
			pf("%d\n",total);
		}
		else if(opr==1) {
			y=y%3;
			int diff=(vec[x-1]+y)-vec[x]+3;
			vec[x]=(vec[x-1]+y)%3;
			fr(j,x+1,n+1) vec[j]=(vec[j]+diff)%3;
		}
		// print(vec);pf("\n");
	}
	return 0;
}