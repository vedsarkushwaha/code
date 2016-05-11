#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <cassert>

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

int debug=0;

void printVec(vi vec) {
	var(int);
	fr(i,0,vec.size()) pf("%d ",vec[i]);
	pf("\n");
}

void printArr(int *arr,int N) {
	var(int);
	fr(i,0,N) pf("%d ",arr[i]);
	pf("\n");
}

int main() {
	var(int);
	int T,N,tc;
	sc("%d",&T);
	int maxCCSize;
	fr(tc,1,T+1) {
		sc("%d",&N);
		int inp[1001];
		vi graph[1001];
		// fr(i,0,N+2) fr(j,0,N+2) graph[i][j]=0;
		int mrk[N+1];
		vi connComp[1000];
		vi connCompSize;
		fr(i,1,N+1) {
			sc("%d",&tmp);
			inp[i]=tmp;
			mrk[i]=0;
			connComp[i].clear();
			graph[i].pb(tmp);
			graph[tmp].pb(i);
		}
		maxCCSize=0;
		// get cycle of length 2
		fr(i,1,N+1) {
			if(debug) pf("%d\n",i);
			if(mrk[i]==0 && inp[inp[i]]==i) {
				// get connCompSize
				if(debug) pf("Found cycle of length 2\n");
				int twoCycleCCSize=1;
				int leftCC=0;
				int rightCC=0;
				int maxDepthLeft=0;
				int maxDepthRight=0;

				mrk[inp[i]]=1;
				mrk[i]=1;

				// left depth
				stack<pair<int,int> > stk;
				stk.push(make_pair(i,1));
				while(!stk.empty()) {
					int currNode = stk.top().first;
					int currDepth = stk.top().second;
					if(debug) pf("currNode currDepth=%d %d\n",currNode, currDepth);
					maxDepthLeft = max(currDepth, maxDepthLeft);
					stk.pop();
					fr(j,0,graph[currNode].size()) {
						int adjNode = graph[currNode][j];
						if(mrk[adjNode]==0) {
							stk.push(make_pair(adjNode,currDepth+1));
							mrk[adjNode]=1;	
						}		
					}
				}

				// right depth
				assert(stk.size()==0);
				stk.push(make_pair(inp[i],1));
				while(!stk.empty()) {
					int currNode = stk.top().first;
					int currDepth = stk.top().second;
					maxDepthRight = max(currDepth, maxDepthRight);
					stk.pop();
					fr(j,0,graph[currNode].size()) {
						int adjNode = graph[currNode][j];
						if(mrk[adjNode]==0) {
							stk.push(make_pair(adjNode,currDepth+1));
							mrk[adjNode]=1;	
						}		
					}
				}
				if(debug) pf("Left - Right Depth = %d %d\n",maxDepthLeft,maxDepthRight);
				connCompSize.pb(maxDepthLeft+maxDepthRight);
			}
		}
		if(debug) printArr(mrk,15);
		fr(i,1,N+1) {
			if(debug) pf("%d\n",i);
			// get cycle
			if(mrk[i]!=i) {
				tmp = i;
				if(debug) pf("Finding connected component\n");
				while(mrk[tmp]!=i) {
					if(debug) pf("in upper loop\n");
					mrk[tmp]=i;
					tmp=inp[tmp];
				}
				// get the cycle size
				int cycleStart = tmp;
				int cycleCurrent= tmp;
				int ccSize=1;
				if(debug) pf("Entering into bigger cycle loop\n");
				while(inp[cycleCurrent]!=cycleStart) {
					// if(debug) pf("in lower loop\n");
					ccSize++;
					cycleCurrent = inp[cycleCurrent];
				}
				maxCCSize=max(maxCCSize,ccSize);
			}
		}
		// sum all 2 cycle connComp
		int twoCycleCCSize=0;
		fr(i,0,connCompSize.size()) twoCycleCCSize+=connCompSize[i];
		if(debug) pf("2cycle - otherCycle: %d %d\n",twoCycleCCSize,maxCCSize);
		// Case #1: 4
		pf("Case #%d: %d\n",tc,max(twoCycleCCSize,maxCCSize));
	}
	return 0;
}