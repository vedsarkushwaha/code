#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <cstring>
#include <cmath>
#include <string>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <climits>
#include <cassert>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1,tmp2,tmp3,tmp
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
using namespace std;
 
bool chkDouble(string S) {
	var(int);
	// cout<<"chkDouble "<<S<<endl;
	tmp = S.length();
	assert(tmp%2==0);
	// cout<<S.substr(0,tmp/2)<<" "<<S.substr(tmp)<<endl;
	if(S.substr(0,tmp/2)==S.substr(tmp/2)) return true;
	else return false;
}
 
int main() {
	var(int);
	int T,flag;
	sc("%d",&T);
	while(T--) {
		string inp;
		cin>>inp;
		if(inp.length()%2==0) {
			if(chkDouble(inp)) pf("YES\n");
			else pf("NO\n");
		}
		else {
			int arr[26]={0};
			fr(i,0,inp.length()) arr[inp[i]-'a']++;
			char ch;
			flag=0;
			fr(i,0,26) {
				if(arr[i]%2!=0) {
					flag++;
					ch='a'+i;
				}
			}
			assert(flag!=0);
			if(flag>1) pf("NO\n");
			else {
				flag=0;
				fr(i,0,inp.length()) {
					if(inp[i]==ch) {
						if(chkDouble(inp.substr(0,i)+inp.substr(i+1))) {
							flag=1;
							break;
						}
					}
				}
				if(flag) pf("YES\n");
				else pf("NO\n");
			}
		}
	}
}