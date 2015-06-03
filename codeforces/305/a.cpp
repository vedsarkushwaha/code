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
bool chk(string str) {
	var(int);
	i=0,j=str.length()-1;
	while(i<j) {
		if(str[i]!=str[j])
			return 0;
		i++,j--;
	}
	return 1;
}
int main() {
	var(int);
	string str,tmpstr1="",tmpstr2="",tmpstr3="";
	cin>>str;
	sc("%d",&k);
	if(str.length()%k!=0) {
		pf("NO");
		return 0;
	}
	tmp=str.length()/k;
	i=0;
	while(i<str.length()) {
		tmpstr1="";
		fr(j,i,i+tmp) {
			tmpstr1+=str[j];
		}
		if(!chk(tmpstr1)) {
			pf("NO");
			return 0;
		}
		i+=tmp;
	}
	pf("YES");
	return 0;
}