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
	ll par;
	vector<ll> vec;
};
int main() {
	var(ll);
	sc("%lld",&T);
	fr(k,1,T+1) {
		tmp5=0;
		sc("%lld",&N);
		node nd[N+1];
		vector<ll> lf;
		vector<ll> trav;
		lf.resize(N+1,0);
		trav.resize(N+1,0);
		fr(j,1,N+1) {
			sc("%lld",&tmp);
			nd[j].par=tmp;
			lf[tmp]=1;
		}
		/*fr(j,1,N+1) {
			pf("%lld %lld\n",j,nd[j].par);
		}*/
		priority_queue<ll> Q;
		fr(j,1,lf.size()) {
			if(lf[j]==0) {
				Q.push(j);
				trav[j]=1;
				//pf("%lld ",j);
				//fflush(stdout);
				//(nd[nd[j].par].vec).pb(1);
			}
		}
		//tmp5+=Q.size();
		while(!Q.empty()) {
			tmp4=Q.top();
			Q.pop();
			if(tmp4==0) {
				break;
			}
			//chk value
			fr(i,1,N+1) {
				if(find((nd[tmp4].vec).begin(),(nd[tmp4].vec).end(),i)==(nd[tmp4].vec).end()) {
					tmp5+=i;
					break;
				}
			}
			//pf("%lld %lld\n",tmp5,tmp4);
			//pf("%lld %lld\n",tmp4,Q.size());
			//fflush(stdout);
			//add to parent
			(nd[nd[tmp4].par].vec).pb(i);
			if(trav[nd[tmp4].par]==0) {
				Q.push(nd[tmp4].par);
				trav[nd[tmp4].par]=1;
			}
			
		}
		pf("Case #%lld: %lld\n",k,tmp5);
	}
	return 0;
}
