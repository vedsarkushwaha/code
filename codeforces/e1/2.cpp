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

int main() {
	string inp;
	var(int);
	inp="0";
	string strTmp;
	cin>>strTmp;
	inp+=strTmp;
	int m;
	sc("%d",&m);
	while(m--) {
		int l,r,k;
		sc("%d %d %d",&l,&r,&k);
		k=k%(r-l+1);
		strTmp=inp;
		fr(i,l,r+1) {
			if(i+k>r) {
				tmp=((i+k)%r);
				tmp=l+tmp-1;
			}
			else tmp=i+k;
			strTmp[tmp]=inp[i];
		}
		fr(i,l,r+1) {
			inp[i]=strTmp[i];
		}
	}
	fr(i,1,inp.length()) pf("%c",inp[i]);
	return 0;
}
