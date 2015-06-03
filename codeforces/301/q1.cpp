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
int get_min(char a,char b) {
	var(int);
	if(a==b)
		return 0;
	tmp=abs(a-b);
	return min(tmp,10-tmp);
}
int main() {
	var(int);
	string ori,fin;
	sc("%d",&N);
	cin>>ori;
	cin>>fin;
	fr(i,0,N) {
		tmp+=get_min(ori[i],fin[i]);
	}
	pf("%d",tmp);
	return 0;
}
