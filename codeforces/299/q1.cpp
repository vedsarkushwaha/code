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
string zeroto20[21]={"zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty"};
string enty[8]={"twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
int main() {
	var(int);
	int n;
	sc("%d",&n);
	if(n<21) {
		cout<<zeroto20[n];
	}
	else {
		cout<<enty[n/10-2];
		if(n%10)
			cout<<"-"<<zeroto20[n%10];
	}
	return 0;
}
