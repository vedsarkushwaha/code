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
int chk_opr(char ch) {
	if((ch=='*')||(ch=='/')||(ch=='+')||(ch=='-')||(ch=='^'))
		return 1;
	else
		return 0;
}
int pri(char a,char b) {
	//return 1 if a<b
	if(a=='+') {
		if(b!='+')
			return 1;
		else
			return 0;
	}
	if(a=='-') {
		if((b=='+')||(b=='-'))
			return 0;
		else
			return 1;
	}
	if(a=='*') {
		if((b=='/')||(b=='^'))
			return 1;
		else
			return 0;
	}
	if(a=='/') {
		if(b=='^')
			return 1;
		else
			return 0;
	}
	if(a=='^') {
		return 0;
	}
}
stack<char> st;
int main() {
	var(int);
	string str;
	int T;
	sc("%d",&T);
	while(T--) {
		//st.clear();
		cin>>str;
		fr(i,0,str.length()) {
			//fflush(stdout);
			if(chk_opr(str[i])) {
				while((!st.empty())&&(st.top()!='(')&&(pri(str[i],st.top()))) {
					//chk for opening bracket here
					pf("%c",st.top());
					//fflush(stdout);
					st.pop();
					if(!st.empty() && st.top()=='(')
						break;
				}
				st.push(str[i]);
			}
			else if(str[i]=='(') {
				st.push('(');
			}
			else if(str[i]==')') {
				while((!st.empty())&&(st.top()!='(')) {
					pf("%c",st.top());
					st.pop();
				}
				if(!st.empty() && st.top()=='(')
					st.pop();
			}
			else {
				pf("%c",str[i]);
			}
		}
		while(!st.empty()) {
			pf("%c",st.top());
			st.pop();
		}
		pf("\n");
	}
	return 0;
}
