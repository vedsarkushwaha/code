#include<bits/stdc++.h>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1=0,tmp2=0,tmp3=0,tmp=0,tmp4=0,tmp5=0,flag=0,T=0,N=0,Q=0
#define pb push_back
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
#define pii pair<int,int>
using namespace std;

/*
0 - empty
1 - blocked
*/


int maxLength=0;
vii 


void dfs(int **mat, int **trav, pii pos, int len) {
	trav[pos.first][pos.second]=1;
	if(len>maxLength) {
		maxLength=len;

	}
	if(mat[pos.first][pos.second+1]==0) {
		dfs(mat,trav,make_pair(pos.first,pos.second+1,1));
	}
	if(mat[pos.first][pos.second-1]==0) {
		dfs(mat,trav,make_pair(pos.first,pos.second+1,1));
	}
	if(mat[pos.first+1][pos.second+1]==0) {
		dfs(mat,trav,make_pair(pos.first,pos.second+1,1));
	}
	if(mat[pos.first+1][pos.second-1]==0) {
		dfs(mat,trav,make_pair(pos.first,pos.second+1,1));
	}
}


vii getLongestPath(int **mat) {
	int trav[602][602]={0};
	vii localPath,globalPath;
	var(int);
	fr(i,1,601) {
		fr(j,1,601) {
			if(trav[i][j]) {
				localPath = dfs(mat,trav,make_pair(i,j),0);
				if(localPath.size()>globalPath.size()) globalPath=localPath;
			}
		}
	}
	return globalPath;
}

int main() {
	var(int);
	int n,m,K;
	int mat[602][602];
	sc("%d %d %d",&n,&m,&K);
	fr(i,0,n+2) fr(j,0,m+2) mat[i][j]=0;
	fr(i,0,K) {
		sc("%d %d",&tmp1,&tmp2);
		mat[tmp1][tmp2]=1;
	}
	pair<int,int> start,end,nextMove;
	vii path;
	start.first=-1;
	while(!IsComplete(mat)) {
		// if current snake is not blocked, then search for new position to move
		// if current snake is blocked, the search for new position to start
		if(start.first==-1) {
			// get some position to start
				// use bfs/dfs to get the largest path and start from the middle of that path
			// set start and end position
			path = getLongestPath(mat);
			start = getMiddleElement(path);
			end = start;
		}
		else {
			// expand start or end of the snake
			nextMoveFromStart = nextMoveInPath(start, path);
			nextMoveFromEnd = nextMoveInPath(end, path);
			if(nextMoveFromStart.first!=-1) {
				start = nextMoveFromStart;
			}
			else if(nextMoveFromEnd.first!=-1) {
				end = nextMoveFromEnd;
			}
			else {
				start.first = -1;
			}
		}
	}
	return 0;
}