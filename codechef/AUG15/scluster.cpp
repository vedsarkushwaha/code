#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>
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
// program is failing because moving on a exsiting guy place. please check weather the place is empty or not before moving
pair<int,int> mat[62][62];
int moved[62][62];

bool chk_nei(pair<int,pair<int,int> > pr) {
	var(int);
	fr(i,-1,2) {
		fr(j,-1,2) {
			if(i==j) continue;
			if(moved[pr.second.first+i][pr.second.second+j]) {
				return true;
			}
		}
	}
	return false;
}

pair<int,int> get_posi(pair<int,pair<int,int> > pr,pair<int,pair<int,int> > hm) {
	var(int);
	while(pr.second.first!=hm.second.first || pr.second.second!=hm.second.second) {
		tmp=pr.second.first-hm.second.first;tmp1=pr.second.second-hm.second.second;
		// pf("tmp=%d tmp1=%d\n",tmp,tmp1);
		assert(moved[pr.second.first][pr.second.second]==0);
		if(chk_nei(pr)) {
			return pr.second;
		}
		if(tmp<0 && tmp1<0) {
			// up left
			if(tmp!=0) pr.second.first++;
			if(tmp1!=0) pr.second.second++;
		}
		else if(tmp>=0 && tmp1<0) {
			// down left
			if(tmp!=0) pr.second.first--;
			if(tmp1!=0) pr.second.second++;
		}
		else if(tmp<0 && tmp1>=0) {
			// up right
			if(tmp!=0) pr.second.first++;
			if(tmp1!=0) pr.second.second--;
		}
		else if(tmp>=0 && tmp1>=0) {
			// down left
			if(tmp!=0) pr.second.first--;
			if(tmp1!=0) pr.second.second--;
		}
	}
	// pf("Error %d %d\n",pr.second.first,pr.second.second);
	return pr.second;
}

void print(int N) {
	var(int);
	fr(i,1,N+1) {
		fr(j,1,N+1) {
			pf("%d ",mat[i][j].first);
		}
		pf("\n");
	}
}

void printM(int N) {
	var(int);
	fr(i,1,N+1) {
		fr(j,1,N+1) {
			pf("%d ",moved[i][j]);
		}
		pf("\n");
	}
}

void markCluster(int x,int y) {
	var(int);
	if(mat[x][y].first!=0) {
		moved[x][y]=1;
		fr(i,-1,2) {
			fr(j,-1,2) {
				if(moved[x+i][y+j]==0) markCluster(x+i,y+j);
			}
		}
	}
	else
		return;
}

int main() {
	var(int);
	int T,N;
	vector<pair<int,pair<int,int> > >vec;
	sc("%d",&T);
	while(T--) {
		int N,K;
		vec.clear();
		sc("%d %d",&N,&K);
		int minX=0,minY=0;
		fr(i,1,N+1) {
			fr(j,1,N+1) {
				sc("%d",&tmp);
				moved[i][j]=0;
				mat[i][j].first=tmp;
				mat[i][j].second=-1;
			}
		}

		int IP[K+1];
		IP[0]=-1;
		int minIP=INT_MAX;
		fr(i,0,K) {
			sc("%d",&tmp);
			IP[i+1]=tmp;
		}
		// cluster the default data
		fr(i,1,N+1) {
			fr(j,1,N+1) {
				if(IP[mat[i][j].first]<minIP) {
					minIP=IP[mat[i][j].first];
					minX=i;
					minY=j;
				}
			}
		}
		markCluster(minX,minY);

		fr(i,1,N+1) {
			fr(j,1,N+1) {
				mat[i][j].second=IP[mat[i][j].first];
				if(mat[i][j].second!=-1 && moved[i][j]==0) {
					moved[i][j]=1;
					vec.pb(make_pair(mat[i][j].second,make_pair(i,j)));
				}
			}
		}
		// print(N);
		sort(vec.begin(),vec.end());
		// pf("\n");
		// printM(N);
		// pf("home %d %d %d\n",vec[0].first,vec[0].second.first,vec[0].second.second);
		ifr(i,vec.size()-1,0) {
			// pf("%d %d\n",vec[i].second.first,vec[i].second.second);
			if(!chk_nei(vec[i])) {
				// pf("no neigh\n");
				pair<int,int> pr = get_posi(vec[i],vec[0]);
				// move
				swap(mat[pr.first][pr.second],mat[vec[i].second.first][vec[i].second.second]);
				swap(moved[pr.first][pr.second],moved[vec[i].second.first][vec[i].second.second]);
			}
		}
		// printM(N);
		// pf("\n");
		print(N);
		pf("\n");
	}
	return 0;
}