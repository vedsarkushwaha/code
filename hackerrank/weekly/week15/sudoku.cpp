#include<bits/stdc++.h>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,l=0,tmp1=0,tmp2=0,tmp3=0,tmp=0,tmp4=0,tmp5=0,flag=0,T=0,N=0,Q=0
#define pb push_back
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
using namespace std;
int arr[9][9];

bool chk(int p,int q) {
	var(int);
	// pf("%d %d\n",p,q);
	fr(k,0,9) {
		if(arr[p][q]==arr[p][k] && q!=k) {
			// pf("%d %d %d\n",p,q,k);
			return 1;
		}
		if(arr[p][q]==arr[k][q] && p!=k) {
			return 1;
		}
	}
	tmp1=3*(p/3),tmp2=3*(q/3);
	fr(k,0,3) {
		fr(l,0,3) {
			if(arr[p][q]==arr[tmp1+k][tmp2+l] && !(p==tmp1+k && q==tmp2+l)) {
				return 1;
			}
		}
	}
	// pf("0");
	return 0;
}
bool chk_solu(vii swp) {
	var(int);
	fr(i,0,swp.size()) {
		if(chk(swp[i].first,swp[i].second))
			return 1;
	}
	return 0;
}
int main() {
	var(int);
	sc("%d",&T);
	// int arr[9][9];
	int cnf[9][9];
	fr(Q,1,T+1) {
		fr(i,0,9) {
			fr(j,0,9) {
				sc("%d",&arr[i][j]);
			}
		}
		fr(i,0,9) {
			fr(j,0,9) {
				cnf[i][j]=0;
				// pf("%d ",arr[i][j]);
			}
			// pf("\n");
		}
		fr(i,0,9) {
			fr(j,0,9) {
				if(chk(i,j)) {
					cnf[i][j]=1;
				}
			}
		}
		vii swp;
		fr(i,0,9) {
			fr(j,0,9) {
				if(cnf[i][j]) {
					swp.pb(make_pair(i,j));
				}
			}
		}
		int flag=0;
		pf("Case #%d:\n",Q);
		// fr(i,0,swp.size()) pf("%d %d\n",swp[i].first,swp[i].second);
		fr(i,0,swp.size()) {
			fr(j,i+1,swp.size()) {
				if(arr[swp[i].first][swp[i].second]!=arr[swp[j].first][swp[j].second]) {
					swap(arr[swp[i].first][swp[i].second],arr[swp[j].first][swp[j].second]);
					if(!chk_solu(swp)) {
						pf("(%d,%d) <-> (%d,%d)\n",swp[i].first+1,swp[i].second+1,swp[j].first+1,swp[j].second+1);
						flag=1;
					}
					swap(arr[swp[i].first][swp[i].second],arr[swp[j].first][swp[j].second]);
				}
			}
		}
		if(!flag) {
			pf("Serendipity\n");
		}
	}
	return 0;
}