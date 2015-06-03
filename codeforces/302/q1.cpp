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
	int n;
	sc("%d\n",&n);
	string str;
	cin>>str;
	int ch[26]={0};
	vector<string> str;
	fr(i,0,str.length()) {
		ch[str[i]-'a']=1;
	}
	fr(i,0,26) if(ch[i]==1) tmp++;
	if(tmp>=n) pf("YES");
	else pf("NO");
	fr(i,0,str.length()) {
		
	}
	return 0;
}