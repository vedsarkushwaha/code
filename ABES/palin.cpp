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
vector<int> vec;
void oct_con(int n) {
	var(int);
	string st;
	vec.clear();
	while(n!=0) {
		vec.push_back(n%8);
		n=n/8;
	}
}
int chk() {
	var(int);
	stack<char> st;
	fr(i,0,vec.size()/2) {
		st.push(vec[i]);
	}
	if(vec.size()%2!=0)
		i++;
	while(i<vec.size()) {
		if(vec[i]==st.top()) {
			st.pop();
		}
		else {
			return -1;
		}
		i++;
	}
	if(st.empty())
		return 1;
}
void print() {
	var(int);
	fr(i,0,vec.size())
		pf("%d ",vec[i]);
}
int main() {
	var(int);
	int T,N;
	sc("%d",&T);
	while(T--) {
		sc("%d",&N);
		oct_con(N);
		//print();
		fflush(stdout);
		pf("%d\n",chk());
	}
	return 0;
}
