#include<bits/stdc++.h>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1=0,tmp2=0,tmp3=0,tmp=0,tmp4=0,tmp5=0,flag=0,T=0,N=0
#define pb push_back
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
using namespace std;
int getnum(int n1,int n2) {
	while(n2--) {
		n1*=10;
	}
	return n1;
}
int main() {
	var(int);
	while(1) {
		sc("%de%d",&tmp1,&tmp2);
		if(tmp1==0 && tmp2==0)
			break;
		tmp5=getnum(tmp1,tmp2);
		tmp4=log2(tmp5);
		tmp4=pow(2,tmp4);
		pf("%d\n",(tmp5-tmp4)*2+1);
	}
	return 0;
}
