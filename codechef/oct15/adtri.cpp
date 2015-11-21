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
#define sz 6000010

using namespace std;

int hypo[sz]={0},prime[sz]={0};
int main() {
  	var(int);
  	fr(i,2,sz) {
	    if(prime[i]==0) {
	      	for(j=i;j<sz;j+=i) {
	        	prime[j]=1;
	        	if(i%4==1) hypo[j]=1;
	      	}
    	}
	}
	sc("%d",&tmp);
	while(tmp--) {
		sc("%d",&tmp1);
		if(hypo[tmp1]) pf("YES\n");
		else pf("NO\n");
	}
	return 0;
}