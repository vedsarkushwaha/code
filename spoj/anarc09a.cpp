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

int main() {
	var(int);
	string str;
	//sc("%d",&T);
	tmp=1;
	while(1) {
		cin>>str;
		if(str[0]=='-')
			break;
		tmp4=0;tmp5=0;
		fr(i,0,str.length()) {
			if(str[i]=='{') {
				tmp4++;
			}
			else {
				if(tmp4>0)
					tmp4--;
				else {
					tmp5++;
					tmp4++;
				}
			}
		}
		pf("%d. %d\n",tmp++,tmp5+tmp4/2);
	}
	return 0;
}
