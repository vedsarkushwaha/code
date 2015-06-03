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
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1,tmp2,tmp3,tmp=0
using namespace std;

int main() {
	var(int);
	string inp,opt,tmpstr,tmpinp;
	set<string> st;
	queue<string> Q,Q1;
	cin>>inp>>opt;
	if(inp==opt) {
		pf("0\n");
		return 0;
	}
	tmp=0;
	Q.push(inp);
	tmp3=0;
	st.insert(inp);
	while(!Q1.empty() || !Q.empty()) {
		while(!Q.empty()) {
			tmpinp=Q.front();
			//cout<<tmpinp<<endl;
			Q.pop();
			tmp1=tmpinp.find('_');
			//cout<<tmp1<<endl;
			if(tmpinp.length()>tmp1+1) {
				tmpstr=tmpinp;
				swap(tmpstr[tmp1],tmpstr[tmp1+1]);
				//cout<<tmpstr<<endl;
				if(opt==tmpstr) {
					pf("%d\n",tmp+1);
					tmp3=1;
					break;
				}
				else {
					if((st.find(tmpstr))==st.end()) {
						//pf("enter");
						st.insert(tmpstr);
						Q1.push(tmpstr);
					}
				}
			}
			if((tmpinp.length()>tmp1+2)&&(tmpinp[tmp1+1]!=tmpinp[tmp1+2])) {
				tmpstr=tmpinp;
				swap(tmpstr[tmp1],tmpstr[tmp1+2]);
				//cout<<tmpstr<<endl;
				if(opt==tmpstr)  {
					pf("%d\n",tmp+1);
					tmp3=1;
					break;
				}
				else {
					if((st.find(tmpstr))==st.end()) {
						//pf("enter");
						st.insert(tmpstr);
						Q1.push(tmpstr);
					}
				}
			}
			if(tmp1>0) {
				tmpstr=tmpinp;
				swap(tmpstr[tmp1],tmpstr[tmp1-1]);
				//cout<<tmpstr<<endl;
				if(opt==tmpstr)  {
				
					pf("%d\n",tmp+1);
					tmp3=1;
					break;
				}
				else {
					if((st.find(tmpstr))==st.end()) {
						//pf("enter");
						st.insert(tmpstr);
						Q1.push(tmpstr);
					}
				}
			}
			if((tmp1>1)&&(tmpinp[tmp1-1]!=tmpinp[tmp1-2])) {
				tmpstr=tmpinp;
				swap(tmpstr[tmp1],tmpstr[tmp1-2]);
				//cout<<tmpstr<<endl;
				if(opt==tmpstr)  {
					pf("%d\n",tmp+1);
					tmp3=1;
					break;
				}
				else {
					if((st.find(tmpstr))==st.end()) {
						//pf("enter");
						st.insert(tmpstr);
						Q1.push(tmpstr);
					}
				}
			}
			//pf("\n");
		}
		//pf("\n%d\n",Q1.size());
		while(!Q1.empty()) {
			Q.push(Q1.front());
			Q1.pop();
		}
		//pf("\n\n");
		//pf("\n%d %d\n",Q.size(),Q1.size());
		tmp++;
		if(tmp3==1)
			break;
	}
	if(tmp3==0)
		pf("Not found\n");
	return 0;
}
