#include<bits/stdc++.h>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1=0,tmp2=0,tmp3=0,tmp=0,tmp4=0,tmp5=0,flag=0
#define pb push_back
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
using namespace std;

char mat[1001][1001],ch;
char dn[1001][1001];
int val[1001][1001];
vii path;

int main() {
	var(int);
	int N,M,K;
	sc("%d %d %d\n",&N,&M,&K);
	
	fr(i,0,N) {
		fr(j,0,M) {
			sc("%c",&mat[i][j]);
			val[i][j]=0;
			dn[i][j]=0;
		}
		sc("%c",&ch);
	}
	stack<pair<int,int> > stk;
	while(K--) {
		sc("%d %d",&i,&j);
		i--;
		j--;
		if(val[i][j]!=0) pf("%d\n",val[i][j]);
		else {
			tmp=0;
			stk.push(make_pair(i,j));
			dn[i][j]=1;
			path.clear();
			while(!stk.empty()) {
				i=stk.top().first;
				j=stk.top().second;
				// pf("%d %d\n",i,j);
				path.pb(make_pair(i,j));
				stk.pop();
				if(mat[i+1][j]=='.') {
					if(!dn[i+1][j]) {
						stk.push(make_pair(i+1,j));
						dn[i+1][j]=1;
					}
				}
				else tmp++;
				
				if(mat[i-1][j]=='.') {
					if(!dn[i-1][j]) {
						stk.push(make_pair(i-1,j));
						dn[i-1][j]=1;
					}
				}
				else tmp++;
				
				if(mat[i][j+1]=='.') {
					if(!dn[i][j+1]) {
						stk.push(make_pair(i,j+1));
						dn[i][j+1]=1;
					}
				}
				else tmp++;
				
				if(mat[i][j-1]=='.') {
					if(!dn[i][j-1]) {
						stk.push(make_pair(i,j-1));
						dn[i][j-1]=1;
					}
				}
				else tmp++;
			}
			pf("%d\n",tmp);
			fr(i,0,path.size()) {
				val[path[i].first][path[i].second]=tmp;
			}
		}
	}
	return 0;
}