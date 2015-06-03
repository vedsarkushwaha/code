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
#define var(x) x i=0,j=0,k=0,tmp1,tmp2,tmp3=0,tmp=0,T
using namespace std;
 
int main() {
	var(int);
	vector<int> vec[10010];
	int arr[10010]={0};
	stack<int> q;
	sc("%d %d",&tmp1,&tmp2);
	fr(i,0,tmp2) {
		sc("%d %d",&j,&k);
		vec[j].push_back(k);
		vec[k].push_back(j);
	}
	//traverse
	q.push(1);
	while(!q.empty()) {
		tmp=q.top();
		arr[tmp]=1;
		q.pop();
		fr(i,0,vec[tmp].size()) {
			if(arr[vec[tmp][i]]!=1) {
				q.push(vec[tmp][i]);
			}
		}
	}
	if(tmp1!=tmp2+1) {
		pf("NO");
		return 0;
	}
	fr(i,1,tmp2+1) {
		if(arr[i]==0) {	
			pf("NO");
			return 0;
		}
	}
	pf("YES");
	return 0;
}
