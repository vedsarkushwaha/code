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
#define var(x) x i=0,j=0,k=0,tmp1,tmp2,tmp3,tmp=0,T,N
using namespace std;
struct node {
	int id,val;
};

int main() {
	var(int);
	sc("%d",&N);
	vector<int> vec[N+1];
	queue<node> Q;
	node src,dst,temp1,temp2;
	int vis[N+1];
	vis[0]=0;vis[N]=0;
	fr(i,1,N) {
		vis[i]=0;
		sc("%d %d",&tmp1,&tmp2);
		vec[tmp1].push_back(tmp2);
		vec[tmp2].push_back(tmp1);
	}
	src.id=0;src.val=0;
	temp1.id=vec[1][0];temp1.val=0;
	Q.push(temp1);
	while(!Q.empty()) {
		temp1.id=(Q.front()).id;
		temp1.val=(Q.front()).val;
		Q.pop();
		vis[temp1.id]=1;
		fr(i,0,vec[temp1.id].size()) {
			if(vis[vec[temp1.id][i]]!=1) {
				temp2.id=vec[temp1.id][i];
				temp2.val=temp1.val+1;
				Q.push(temp2);
				if(src.val<temp2.val) {
					src.val=temp2.val;
					src.id=temp2.id;
				}
			}
		}
	}
	fr(i,0,N+1)
		vis[i]=0;
	dst.id=0;dst.val=0;
	src.val=0;
	Q.push(src);
	while(!Q.empty()) {
		temp1.id=(Q.front()).id;
		temp1.val=(Q.front()).val;
		Q.pop();
		vis[temp1.id]=1;
		fr(i,0,vec[temp1.id].size()) {
			if(vis[vec[temp1.id][i]]!=1) {
				temp2.id=vec[temp1.id][i];
				temp2.val=temp1.val+1;
				Q.push(temp2);
				if(dst.val<temp2.val) {
					dst.val=temp2.val;
					dst.id=temp2.id;
				}
			}
		}
	}
	pf("%d\n",dst.val);
	return 0;
}
