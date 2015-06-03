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
char chg(char ch) {
	if(ch=='1') return '0';
	else return '1';
}
int main() {
	var(int);
	char ch;
	int n;
	vector<char> inp;
	vector<char> opt;
	sc("%d",&T);
	while(T--) {
		inp.clear();
		opt.clear();
		int flag=0;
		sc("%d %d\n",&n,&k);
		fr(i,0,n) {
			sc("%c",&ch);
			inp.pb(ch);
		}
		sc("%c",&ch);
		if(k==1) {
			int tmpZero=0,tmpOne=0;
			fr(i,0,n) {
				if(inp[i]=='0' && i%2==0) tmpOne++;
				else if(inp[i]=='1' && i%2==1) tmpOne++;
				if(inp[i]=='1' && i%2==0) tmpZero++;
				else if(inp[i]=='0' && i%2==1) tmpZero++;
			}
			pf("%d\n",min(tmpZero,tmpOne));
			if(tmpZero<tmpOne) {
				fr(i,0,n) {
					pf("%d",i%2);
				}
			}
			else{
				fr(i,0,n) {
					pf("%d",1-(i%2));
				}
			}
			pf("\n");
		}
		else {
			i=-1;
			int swp=0;
			while(i<n) {
				i++;
				opt.pb(inp[i]);
				tmp=1;
				while(i<n-1 && inp[i]==inp[i+1]) {
					tmp++;
					i++;
				}
				// if(inp[i]!=inp[i+1]) i++;
				ch=inp[i];	
				if(tmp%(k+1)==0) {
					fr(j,1,tmp-2) {
						if(j%(k)==0) {
							opt.pb(chg(ch));
							// cout<<"i";
							swp++;
						}
						else {
							opt.pb(ch);
							// cout<<"j";
						}
					}
					opt.pb(chg(ch));
					swp++;
					opt.pb(ch);
				}
				else {
					fr(j,1,tmp) {
						if(j%(k)==0) {
							opt.pb(chg(ch));
							swp++;
							// cout<<"k";
						}
						else {
							opt.pb(ch);
							// cout<<"l";
						}
					}
				}
			}
			pf("%d\n",swp);
			fr(i,0,opt.size()) pf("%c",opt[i]);
			pf("\n");
		}
	}
	return 0;
}