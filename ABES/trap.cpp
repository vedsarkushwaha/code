#include<cstdio>
#include<iostream>
#include<vector>
#include<stack>
#include<map>
#include<set>
#include<cstring>
#include<cmath>
#include<string>
#include<cstdlib>
#include<queue>
#include<algorithm>
#include<climits>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1,tmp2,tmp3,tmp=0
using namespace std;

int main() {
	var(int);
	string str;
	stack<int> st;
	getline(cin,str);
	fr(i,0,str.length()) {
		if ((str[i]=='(')||(str[i]==')')||(str[i]=='{')||(str[i]=='}')||(str[i]=='[')||(str[i]==']')) {
			if((!st.empty())&&(((st.top()=='(') && (str[i]==')'))||((st.top()=='{') && (str[i]=='}'))||((st.top()=='[') && (str[i]==']')))) {
				//pf(" pop ");
				st.pop();
			}
			else {
				st.push(str[i]);
				//pf(" push ");
			}
			//pf("b");
		}
	}
	if(st.empty()==true)
		pf("1");
	else
		pf("0");
	
	return 0;
}
