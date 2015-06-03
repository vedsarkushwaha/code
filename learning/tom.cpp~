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

int main() {
	var(int);
	int N,M,T;
	pair<int,int> src,dst,curr;
	sc("%d",&T);
	queue<pair<int,int> > Q;
	while(T--) {
		sc("%d %d",&N,&M);
		int arr[N][M];
		char inp[N][M];
		sc("%d",&tmp);
		fr(i,0,N) {
			fr(j,0,M) {
				sc("%c",&inp[i][j]);
				arr[i][j]=INT_MAX;
				if(inp[i][j]=='S') {
					src.first=i;src.second=j;
				}
				if(inp[i][j]=='E') {
					dst.first=i;dst.second=j;
				}
			}
			sc("%d",&tmp);
		}
		//traverse
		arr[src.first][src.second]=0;
		//pf("%d %d\n",src.first,src.second);
		Q.push(make_pair(src.first,src.second));
		while(!Q.empty()) {
			curr=Q.front();
			Q.pop();
			fr(i,-1,2) {
				fr(j,-1,2) {
					if(((i==0)&&(j==0))||(curr.first+i<0)||(curr.second+j<0)||(curr.first+i>=N)||(curr.second+j>=M))
						continue;
					if(inp[curr.first+i][curr.second+j]=='*')
						continue;
					if(arr[curr.first+i][curr.second+j]>1+arr[curr.first][curr.second]) {
						Q.push(make_pair(curr.first+i,curr.second+j));
						arr[curr.first+i][curr.second+j]=1+arr[curr.first][curr.second];
					}
				}
			}
		}
		fr(i,0,N) {
			fr(j,0,N) {
				pf("%d ",arr[i][j]);
			}
			pf("\n");
		}
		/*fr(i,0,N) {
			fr(j,0,N) {
				pf("%c",inp[i][j]);
			}
			pf("\n");
		}*/
	}
	return 0;
}
