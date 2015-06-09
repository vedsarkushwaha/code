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
	string str1,str2,str3,str4;
	cin>>str1;
	tmp1=-1;
	while((tmp1=str1.find("AB",tmp1+1))!=string::npos) {
		tmp2=str1.find("BA",tmp1+2);
		if(tmp2!=string::npos) {
			if(abs(tmp1-tmp2)>1) {
				pf("YES");
				return 0;
			}
			else break;
		}
		else break;
	}
	tmp1=-1;
	while((tmp1=str1.find("BA",tmp1+1))!=string::npos) {
		tmp2=str1.find("AB",tmp1+2);
		if(tmp2!=string::npos) {
			if(abs(tmp1-tmp2)>1) {
				pf("YES");
				return 0;
			}
			else break;
		}
		else break;
	}
	pf("NO");
	return 0;
}
