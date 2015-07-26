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

bool comp(pair<ll,ll> pr, ll val) {return pr.first<val;}
bool comp1(ll val, pair<ll,ll> pr) {return pr.first>val;}

int main() {
	var(ll);
	sc("%lld %lld",&N,&Q);
	ll K=sqrt(N);
	vll vec;
	vll::iterator itl,itu;
	ll addArr[1000000]={0};
	fr(i,0,N) {
		sc("%lld",&tmp);
		vec.pb(make_pair(tmp,i));
	}
	ll cnt=0;
	fr(i,0,N/K) {
		sort(vec.begin()+i*K,vec.begin()+(i+1)*K);
		cnt+=(vec.begin()+(i+1)*K - vec.begin() - i*K);
		// pf("%lld ",cnt);
	}
	sort(vec.begin()+i*K,vec.end());
	cnt+=(vec.end() - vec.begin() - i*K);
	assert(cnt==N);
	// pf("%lld\n",cnt);
	while(Q--) {
		ll t;
		flag=0;
		sc("%lld",&t);
		if(t==1) {
			ll l,r,x;
			sc("%lld %lld %lld",&l,&r,&x);
			cnt=0;
			ll lLower=l/K;
			ll lUpper=r/K;
			fr(i,l-1, min((lLower+1)*K,r) ) {
				vec[i].first+=x;
				cnt++;
			}
			
			if(lLower!=lUpper) {
				fr(i,lUpper*K,r) {
					vec[i].first+=x;
					cnt++;
				}
			}
			sort(vec.begin()+lUpper*K,vec.begin()+min((lUpper+1)*K,N));
			
			if(abs(lLower-lUpper)>=2) {
				fr(i,lLower+1,lUpper) {
					addArr[i]+=x;
					cnt=cnt+(K);
				}
			}
			assert(cnt==r-l+1);
		}
		else if(t==2) {
			ll y;
			sc("%lld",&y);
			ll left=INT_MAX,right=INT_MIN;
			cnt=0;
			ll cnt1=0;
			fr(i,0,N/K) {
				cnt+=(vec.begin()+(i+1)*K - vec.begin()-(i*K));
				// if(left==INT_MAX) {
					itl=lower_bound(vec.begin()+(i*K),vec.begin()+(i+1)*K,y-addArr[i],comp);
					if(itl->first==y && (itl<vec.begin()+(i+1)*K)) left=min(left,itl->second);
				// }
				// else break;
				// pf("%lld ",cnt);
			}
			ifr(i,N/K-1,-1) {
				cnt1+=(vec.begin()+(i+1)*K - vec.begin()-(i*K));
				// if(right==INT_MIN) {
					itu=upper_bound(vec.begin()+(i*K),vec.begin()+(i+1)*K,y-addArr[i],comp1);
					itu--;
					if(itu->first==y-addArr[i]) right=max(right,itu->second);
				// }
				// else break;
			}
			itl=lower_bound(vec.begin()+((N/K)*K),vec.end(),y-addArr[i],comp);
			cnt+=(vec.end() - vec.begin()-((N/K)*K));
			
			itu=upper_bound(vec.begin()+((N/K)*K),vec.end(),y-addArr[i],comp1);
			cnt1+=(vec.end() - vec.begin()-((N/K)*K));
			
			if(itl->first==y && (itl<vec.end())) left=min(left,itl->second);
			itu--;
			if(itu->first==y-addArr[i]) right=max(right,itu->second);

			if(left==INT_MAX && right==INT_MIN) pf("-1\n");
			else if(left==INT_MAX || right==INT_MIN) pf("0\n");
			else pf("%lld\n",right-left);
			assert(cnt==N && cnt1==N);
			// pf("%lld %lld\n",cnt,cnt1);
		}
		else {
			fr(i,0,N) pf("%lld ",addArr[i/K]+vec[i].first);
			pf("\n");
		}
	}
	return 0;
}