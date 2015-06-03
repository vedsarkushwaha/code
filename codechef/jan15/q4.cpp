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
	sc("%d",&T);
	vii vec;
	while(T--) {
		sc("%d",&N);
		vec.clear();
		fr(i,0,N) {
			sc("%d %d",&tmp1,&tmp2);
			vec.pb(make_pair(tmp2,tmp1));
		}
		sort(vec.begin(),vec.end());
		/*fr(i,0,N) {
			pf("%d %d\n",vec[i].first,vec[i].second);
		}*/
		tmp3=0;
		i=0;
		tmp5=-1;
		while(i<N) {
			if(tmp5<vec[i].second) {
				tmp3++;
				//while((i<N-1)&&(vec[i].first==vec[i+1].first)) {i++;}
				tmp5=vec[i].first;
			}
			i++;
		}
		pf("%d\n",tmp3);
	}
	return 0;
}
