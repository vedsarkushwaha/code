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
	sc("%d",&T);
	string str1,str2;
	while(T--) {
		set<string> st;
		sc("%d",&N);
		cin>>str1;
		tmp5=(1<<N);
		fr(i,1,tmp5) {
			str2="";
			fr(j,0,N+1) {
				if(i&(1<<j))
					str2+=str1[j];
			}
			// cout<<str2<<endl;
			st.insert(str2);
		}
		set<string>::iterator it;
		for(it=st.begin();it!=st.end();++it) {
			cout<<*it<<endl;
		}
	}
	return 0;
}
