#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>

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
	int R,G,B;
	string color;
	sc("%d\n",&T);
	while(T--) {
		R=0,G=0,B=0;
		sc("%d\n",&N);
		cin>>color;
		fr(i,0,color.size()) {
			if(color[i]=='R') R++;
			else if(color[i]=='G') G++;
			else if(color[i]=='B') B++;
		}
		pf("%d\n",N-(max(max(R,G),B)));
	}
	return 0;
}