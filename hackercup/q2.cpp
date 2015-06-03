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
struct node {
	int p,c,f;
};
int main() {
	var(int);
	vector<node> vec;
	node tmpnd1,tmpnd2,tmpnd3;
	sc("%d",&T);
	fr(i,1,T+1) {
		sc("%d %d %d",&tmp3,&tmp4,&tmp5);
		sc("%d",&N);
		vec.clear();
		fr(j,0,N) {
			sc("%d %d %d",&tmp,&tmp1,&tmp2);
			tmpnd1.p=tmp,tmpnd1.c=tmp1,tmpnd1.f=tmp2;
			vec.pb(tmpnd1);
		}
		fr(Q,0,1<<N) {
			//pf("%d\n",Q);
			tmp=0,tmp1=0,tmp2=0;
			k=0;
			fr(j,0,31) {
				if((Q&(1<<j))==(1<<j)) {
					tmp+=vec[j].p,tmp1+=vec[j].c,tmp2+=vec[j].f;
					//pf(" %d add ",j);
				}
			}
			//if(Q==21)
				//pf("%d %d %d\n",tmp,tmp1,tmp2);
			if((tmp==tmp3)&&(tmp1==tmp4)&&(tmp2==tmp5)) {
				pf("Case #%d: yes\n",i);
				k=1;
				break;
			}
		}
		if(k==0)
			pf("Case #%d: no\n",i);
	}
	return 0;
}
