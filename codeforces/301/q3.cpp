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
	int r,c,inity,initx,finy,finx;
	char ch;
	sc("%d %d\n",&r,&c);
	char mat[r+2][c+2];
	int visi[r+2][c+2];
	fr(i,0,r+2) {
		fr(j,0,c+2) {
			visi[i][j]=0;
			if(j==c+1 && (i!=0 && i!=r+1))
				sc("%c",&ch);
			if(i==0 || j==0 || i==r+1 || j==c+1) {
				mat[i][j]='X';
			}
			else {
				sc("%c",&mat[i][j]);
			}
		}
	}
	sc("%d %d",&initx,&inity);
	sc("%d %d",&finx,&finy);
	tmp1=0;
	if(mat[finx+1][finy]=='.')
		tmp1++;
	if(mat[finx-1][finy]=='.')
		tmp1++;
	if(mat[finx][finy-1]=='.')
		tmp1++;
	if(mat[finx][finy+1]=='.')
		tmp1++;
	if(initx==finx && inity==finy) {
		if(tmp1>0) {
			pf("YES");
			return 0;
		}
		else {
			pf("NO");
			return 0;
		}
	}
	if(mat[finx][finy]=='X') {
		if(finx==initx && finy+1==inity) {
			pf("YES");
			return 0;
		}
		else if(finx==initx && finy-1==inity) {
			pf("YES");
			return 0;
		}
		else if(finx+1==initx && finy==inity) {
			pf("YES");
			return 0;
		}
		else if(finx-1==initx && finy==inity) {
			pf("YES");
			return 0;
		}
	}
	if(mat[finx][finy]=='.') {
		if(finx==initx && finy+1==inity && tmp1>0) {
			pf("YES");
			return 0;
		}
		else if(finx==initx && finy-1==inity  && tmp1>0) {
			pf("YES");
			return 0;
		}
		else if(finx+1==initx && finy==inity  && tmp1>0) {
			pf("YES");
			return 0;
		}
		else if(finx-1==initx && finy==inity  && tmp1>0) {
			pf("YES");
			return 0;
		}
	}
	stack<pair<int,int> > stk;
	stk.push(make_pair(initx,inity));
	pair<int,int> pr;
	while(!stk.empty()) {
		pr=stk.top();
		stk.pop();
		// pf("%d %d\n",pr.first,pr.second);
		visi[pr.first][pr.second]=1;
		if(pr.first==finx && pr.second==finy) {
			tmp=1;
			break;
		}
		if(mat[pr.first+1][pr.second]=='.' && visi[pr.first+1][pr.second]==0)
			stk.push(make_pair(pr.first+1,pr.second));
		if(mat[pr.first-1][pr.second]=='.' && visi[pr.first-1][pr.second]==0)
			stk.push(make_pair(pr.first-1,pr.second));
		if(mat[pr.first][pr.second+1]=='.' && visi[pr.first][pr.second+1]==0)
			stk.push(make_pair(pr.first,pr.second+1));
		if(mat[pr.first][pr.second-1]=='.' && visi[pr.first][pr.second-1]==0)
			stk.push(make_pair(pr.first,pr.second-1));
		
		if(mat[pr.first+1][pr.second]=='X') {
			if(pr.first+1==finx && pr.second==finy) {
				pf("YES");
				return 0;
			}
		}
		if(mat[pr.first-1][pr.second]=='X') {
			if(pr.first-1==finx && pr.second==finy) {
				pf("YES");
				return 0;
			}
		}
		if(mat[pr.first][pr.second+1]=='X') {
			if(pr.first==finx && pr.second+1==finy) {
				pf("YES");
				return 0;
			}	
		}
		if(mat[pr.first][pr.second-1]=='X') {
			if(pr.first==finx && pr.second-1==finy) {
				pf("YES");
				return 0;
			}
		}
	}
	if(!tmp) {
		pf("NO");
		return 0;
	}
	else if(mat[finx][finy]=='X' && tmp1>0) {
		pf("YES");
		return 0;
	}
	if(tmp1>1)
		pf("YES");
	else
		pf("NO");
	return 0;
}