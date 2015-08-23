#include <vector>
#include <algorithm>
#include <cstdio>
#include <stack>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1=0,tmp2=0,tmp3=0,tmp=0,tmp4=0,tmp5=0,flag=0
#define pb push_back
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
using namespace std;

void printVec(vi &vec) {
	var(int);
	fr(i,0,vec.size()) {
		pf("%d ",vec[i]);
	}
}

void stockSpan(vector<int> &input, vector<int> &fromLeft) {
	var(int);
	stack<pair<int,int> > stk;
	// from left
	stk.push(make_pair(input[0],1));
	fromLeft.pb(1);
	fr(i,1,input.size()) {
		int sum=1;
		while(!stk.empty() && stk.top().first<input[i]) {
			sum+=stk.top().second;
			stk.pop();
		}
		stk.push(make_pair(input[i],sum));
		fromLeft.pb(sum);
	}
}

int main() {
	var(int);
	int N;
	sc("%d",&N);
	vi vec,lft,rgt;
	fr(i,0,N) {
		sc("%d",&tmp);
		vec.pb(tmp);
	}
	stockSpan(vec,lft,rgt);
	printVec(vec);
	pf("\n");
	printVec(lft);
	pf("\n");
	printVec(rgt);
	return 0;
}