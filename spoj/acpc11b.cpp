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
	vi vec1,vec2;
	sc("%d",&T);
	while(T--) {
		vec1.clear(),vec2.clear();
		sc("%d",&N);
		while(N--) {
			sc("%d",&tmp);
			vec1.pb(tmp);
		}
		sc("%d",&N);
		while(N--) {
			sc("%d",&tmp);
			vec2.pb(tmp);
		}
		sort(vec1.begin(),vec1.end());
		sort(vec2.begin(),vec2.end());
		i=0,j=0;
		tmp3=INT_MAX;
		tmp4=0;
		while(i<vec1.size() && j<vec2.size()) {
			if(vec1[i]<vec2[j]) {
				tmp3=min(tmp3,vec2[j]-vec1[i]);
				i++;
			}
			else if(vec1[i]>vec2[j]) {
				tmp3=min(tmp3,vec1[i]-vec2[j]);
				j++;
			}
			else {
				pf("%d\n",0);
				tmp4=1;
				break;
			}
		}
		if(tmp4==0)
			pf("%d\n",tmp3);
	}
	return 0;
}
