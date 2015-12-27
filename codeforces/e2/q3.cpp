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
	string str;
	cin>>str;
	int arr[26]={0};
	fr(i,0,str.length()) {
		arr[str[i]-'a']++;
	}
	// fr(i,0,26) pf("%d",arr[i]);
	// pf("\n");
	fr(i,0,26) {
		if(arr[i]%2) {
			ifr(j,25,i) {
				if(arr[j]%2) {
					arr[j]--;
					arr[i]++;
					break;
				}
			}
		}
	}
	// fr(i,0,26) pf("%d",arr[i]);
	// pf("\n");
	j=0;
	k=str.length()-1;
	int mid=str.length()/2;
	fr(i,0,26) {
		while(arr[i]>=2 && arr[i]!=0) {
			str[j]='a'+i;
			str[k]='a'+i;
			j++;k--;
			arr[i]-=2;
		}
		if(arr[i]==1) {
			assert(flag==0);
			flag=1;
			assert(str.length()%2==1);
			str[mid]='a'+i;
			arr[i]=0;
		}
		// cout<<str<<endl;
	}
	cout<<str<<endl;
	return 0;
}
