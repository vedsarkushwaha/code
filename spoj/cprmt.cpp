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
	int arr1[26],arr2[26];
	string str1,str2;
	while(cin>>str1>>str2) {
		fr(i,0,26) {
			arr1[i]=0,arr2[i]=0;
		}
		fr(i,0,str1.length()) {
			arr1[str1[i]-'a']+=1;
		}
		fr(i,0,str2.length()) {
			arr2[str2[i]-'a']+=1;
		}
		fr(i,0,26) {
			tmp3=min(arr1[i],arr2[i]);
			fr(j,0,tmp3) {
				pf("%c",'a'+i);
			}
		}
		pf("\n");
	}
	return 0;
}