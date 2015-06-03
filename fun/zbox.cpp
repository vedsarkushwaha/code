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
int z_box(string str,int *Z) {
	var(int);
	int n;
	Z[0]=str.length();
	int rt=0,lt=0;
	fr(k,1,str.length()) {
		if(k>lt) {
			n=0;
			while(n+k<str.length() && str[n]==str[n+k]) {
				n++;
			}
			Z[k]=n;
			if(n>0) {
				lt=k;
				rt=k+n-1;
			}
			else {
				int p=k-lt;
				int rpl=rt-k+1;
				if(Z[p]<rpl)
					Z[k]=Z[p];
				else {
					i=rt+1;
					while(i<str.length() && str[i]==str[i-k]) {
						i++;
					}
					Z[k]=i-k;
					lt=k;
					rt=i-1;
				}
			}
		}
	}
}
int main() {
	var(int);
	int n;
	string str;
	cin>>str;
	int arr[str.length()+1];
	z_box(str,arr);
	// fr(i,0,str.length()) {
	// 	pf("%d ",arr[i]);
	// }
	// pf("\n");
	return 0;
}