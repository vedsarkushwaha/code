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
#define f(i,m,n) for(i=m;i<n;i++)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1,tmp2,tmp3,tmp=0
using namespace std;

int main() {
	var(int);
	int T,N,U,V;
	vector<int> arr[10001];
	queue<int> Q;
	vector<int> lvl;
	sc("%d",&T);
	while(T--) {
		sc("%d",&N);
		N--;
		tmp=N;
		while(N--) {
			sc("%d %d",&tmp1,&tmp2);
			arr[tmp1].push_back(tmp2);
			//sarr[tmp2].push_back(tmp1);
		}
		Q.push(1);
		Q.push(0);
		tmp2=0;
		while(!Q.empty()) {
			i=Q.front();
			Q.pop();
			//pf("%d %d\n",i,Q.size());
			if(i==0) {
				lvl.push_back(tmp2);
				//pf("%d\n",tmp2);
				tmp2=0;
				if(Q.size()!=0)
					Q.push(0);
			}
			else {
				tmp2++;
				//pf("el");
				//pf(" %d ",arr[i].size());
				f(j,0,arr[i].size()) {
					//pf("e%de",arr[i][j]);
					Q.push(arr[i][j]);
				}
			}
		}
		tmp1=tmp+1;
		i=0;
		int cnt=0;
		while(tmp1>0) {
			tmp1=tmp1-lvl[i];
			i++;
			tmp2++;
			if(tmp1<=0)
				break;
			tmp1--;
			tmp2++;
			if(tmp1<=0)
				break;
		}
		for(i=0;i<tmp+1;i++)
			arr[i].clear();
		lvl.clear();
		pf("%d\n",tmp2);
	}
	return 0;
}