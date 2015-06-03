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

int main() {
	var(int);
	char chess[60][60],ch;
	sc("%d\n",&N);
	vii vec;
	fr(i,0,N+1) {
		fr(j,0,N+1) {
			if(i==0 || j==0)
				chess[i][j]=',';
			else {
				sc("%c",chess[i][j]);
				if(chess[i][j]=='o')
					vec.pb(make_pair(i,j));
			}
		}
		sc("%c",ch);
	}
	int rock=0,bishop=0,king=0,queen=0,pawn=0,knight=0;
	fr(i,0,vec.size()) {
		tmp4=vec[i].first,tmp5=vec[i].second
		fr(j,1,N+1) {
			if((chess[j][tmp5]=='.' && j!=tmp4)||(chess[tmp4][j]=='.'&&j!=tmp5)) {
				rock=1;
				queen=1;
			}
		}
		fr(j,-1,1) {
			fr(k,-1,1) {
				if(chess[tmp4+i][tmp5+j]==',')
					king=1;
			}
		}
		
	}

	return 0;
}
