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
using namespace std;
int N;
int arr[100010];
int tree[410010];
int lazy[410010];
int rate[100010];

void init_tree(int N) {
	int i;
	fr(i,0,4*N) {
		tree[i]=INT_MAX;
		lazy[i]=INT_MAX;
	}
}
void update_tree(int node, int a, int b, int i, int j, int value) {
  	if(lazy[node] != INT_MAX) {
   		tree[node] = min(tree[node],lazy[node]);
		if(a != b) {
			lazy[node*2] = min(lazy[node*2],lazy[node]);
    		lazy[node*2+1] = min(lazy[node*2+1],lazy[node]);
		}
   		lazy[node] = INT_MAX;
  	}
	if(a>b||a>j||b<i) return;    
  	if(a>=i && b<=j) {
    	tree[node]=min(tree[node],value);
		if(a!=b) {
			lazy[node*2]=min(lazy[node*2], value);
			lazy[node*2+1]=min(lazy[node*2+1], value);
		}
		return;
	}
	update_tree(node*2,a,(a+b)/2,i,j,value);
	update_tree(1+node*2,1+(a+b)/2,b,i,j,value);
	tree[node] = min(tree[node*2],tree[node*2+1]);
}
int query_tree(int node, int a, int b, int i, int j) {
	if(a>b || a>j || b<i) return INT_MAX;
	if(lazy[node]!=INT_MAX) {
		tree[node]=min(tree[node],lazy[node]);
		if(a!=b) {
			lazy[node*2]=min(lazy[node],lazy[node*2]);
			lazy[node*2+1]=min(lazy[node],lazy[node*2+1]);
		}
		lazy[node]=INT_MAX;
	}
	if(a>=i && b<=j)
		return tree[node];
	int q1=query_tree(node*2,a,(a+b)/2,i,j);
	int q2=query_tree(1+node*2,1+(a+b)/2,b,i,j);
	int res=min(q1,q2);
	return res;
}

ll K[100010][510];
vi vecWt,vecVal;

ll knapSack(int W, int n) {
   	int i,w;
   	for(i=1;i<=n;i++) {
       	for(w=1;w<=W;w++) {
           	if(vecWt[i-1]<=w) K[i][w]=max(vecVal[i-1]+K[i-1][w-vecWt[i-1]],K[i-1][w]);
           	else K[i][w]=K[i-1][w];
       	}
   	}
  	return K[n][W];
}
int main() {
	var(int);
	sc("%d",&T);
	int M,K,l,r,val;
	while(T--) {
		sc("%d %d %d",&N,&K,&M);
		ll finRate=0;
		tmp5=0;
		fr(i,0,N) {
			arr[i]=INT_MAX;
			sc("%d",rate+i);
			finRate+=rate[i];
			rate[i]=-1*rate[i];
		}
		init_tree(N);
		fr(i,0,M) {
			sc("%d %d %d",&l,&r,&val);
			update_tree(1,1,N,l,r,val);
		}
		fr(i,0,N) {
			arr[i]=query_tree(1, 1, N, i+1, i+1);
		}
		vecWt.clear(), vecVal.clear();
		fr(i,0,N) if(rate[i]>0) {
			vecVal.pb(rate[i]);
			vecWt.pb(arr[i]);
		}
		ll tmpx=knapSack(K,vecWt.size());
		finRate+=tmpx;
		pf("%lld\n",finRate);
	}
	return 0;
}