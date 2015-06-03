#include<bits/stdc++.h>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1=0,tmp2=0,tmp3=0,tmp=0,tmp4=0,tmp5=0,flag=0,T=0,N=0,I=0
#define pb push_back
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
#define sz 10000
using namespace std;
int main() {
	var(int);
	sc("%d",&T);
	fr(k,1,T+1) {
		sc("%d %d",&N,&I);
		vi mat[N+1];
		fr(i,0,I) {
			sc("%d %d",&tmp1,&tmp2);
			mat[tmp1].pb(tmp2);
			mat[tmp2].pb(tmp1);
		}
		vi vis(N+1,0);
		fr(i,1,N+1) {
			if(vis[i]==0) {
				stack<int> st;
				st.push(i);
				vis[i]=1;
				tmp4=0;
				while(!st.empty()) {
					tmp5=st.top();
					st.pop();
					fr(j,0,mat[tmp5].size()) {
						if(vis[mat[tmp5][j]]) {
							pf("Cycle\n");
							tmp4=1;
							break;
						}
						else {
							st.push(mat[tmp5][j]);
							vis[mat[tmp5][j]]=1;
						}
					}
					if(tmp4)
						break;
				}
			}
			if(tmp4)
				break;
		}O