#include<bits/stdc++.h>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1=0,tmp2=0,tmp3=0,tmp=0,tmp4=0,tmp5=0,flag=0,T=0,N=0,Q
#define pb push_back
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
using namespace std;

int main() {
	int arr[1000000];
	var(int);
	N=0;
	vi vec;
	sc("%d",&Q);
	while(Q--) {
		sc("%d %d",&tmp1,&tmp2);
		if(tmp1==0) {
			//vec.pb(tmp2);
			arr[N]=tmp2;N++;
		}
		else if(tmp1==1) {
			sc("%d %d",&tmp3,&tmp4);
			tmp5=0;
			fr(i,tmp2,tmp3+1) {
				tmp5=max(tmp5,tmp4^arr[i-1]);
			}
			pf("%d\n",tmp5^tmp4);
		}
		else if(tmp1==2) {
			N-=tmp2;
		}
		else if(tmp1==3) {
			tmp5=0;
			sc("%d %d",&tmp3,&tmp4);
			fr(i,tmp2,tmp3+1) {
				if(arr[i-1]<=tmp4)
					tmp5++;
			}
			pf("%d\n",tmp5);
		}
		else if(tmp1==4) {
			vec.clear();
			sc("%d %d",&tmp3,&tmp4);
			fr(i,tmp2,tmp3+1)
				vec.pb(arr[i-1]);
			sort(vec.begin(),vec.end());
			pf("%d\n",vec[tmp4-1]);
		}
		else if(tmp1==5) {
			fr(i,0,N)
				pf("%d ",arr[i]);
			pf("\n");
		}
	}
	return 0;
}
