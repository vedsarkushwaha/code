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
vector<int> vec[100000];
int visit[100000];
void dfs() {
	var(int);
	stack<int> st;
	st.push(1);
	pf("%d ",1);
	while(!st.empty()) {
		tmp=st.top();
		st.pop();
		visit[tmp]=1;
		fr(i,0,vec[tmp].size()) {
			if(visit[vec[tmp].at(i)]!=1) {
				st.push(vec[tmp].at(i));
				//pf("%d ",vec[tmp].at(i));
			}
		}
	}
}
int main() {
	var(int);
	int N;
	sc("%d",&N);
	fr(i,0,N-1) {
		sc("%d %d",&tmp1,&tmp2);
		vec[tmp1].push_back(tmp2);
		vec[tmp2].push_back(tmp1);
	}
	dfs();
	return 0;
}
