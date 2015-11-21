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

void print(vi vec) {
	var(int);
	fr(i,0,vec.size()) {
		pf("%d",vec[i]);
	}
}
int main() {
	var(int);
	int m,s;
	sc("%d %d",&m,&s);
	if(9*m<s || (s==0 && m!=1)) {
		pf("-1 -1\n");
		return 0;
	}
	// largest
	vi vec;
	tmp=s;
	while(tmp) {
		if(tmp>=9) {
			vec.pb(9);
			tmp-=9;
		}
		else {
			vec.pb(tmp);
			tmp-=tmp;
		}
	}
	if(vec.size()>m) {
		pf("-1 -1\n");
		return 0;		
	}
	while(vec.size()<m) {
		vec.pb(0);
	}

	// smallest
	vi sml;
	tmp=s;
	tmp1=m-1;
	while(sml.size()!=m) {
		sml.pb(0);
	}
	
	sml[0]=1;tmp--;
	while(tmp) {
		if(tmp1==0) {
			if(tmp>8) {
				pf("-1 -1\n");
				return 0;
			}
			else {
				sml[tmp1]+=tmp;
				tmp-=tmp;
				break;
			}
		}
		if(tmp>=9) {
			sml[tmp1]=9;
			tmp1--;
			tmp-=9;
		}
		else {
			sml[tmp1]=tmp;
			tmp-=tmp;
			tmp1--;
		}
	}
	print(sml);
	pf(" ");
	print(vec);
	return 0;
}