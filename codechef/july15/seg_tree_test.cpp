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
 
#define N 4
#define MAX (1+(1<<3)) // Why? :D
 
using namespace std;
struct nd {
	int val,l,r;
};
int arr[N];
int tree[MAX];
nd lazy[MAX];
void init() {
	int i;
	fr(i,0,MAX) {
		tree[i]=0;
		lazy[i].val=0;
		lazy[i].l=0;
		lazy[i].r=0;
	}
}
void build_tree(int node, int a, int b) {
  	if(a > b) return;
  	
  	if(a == b) {
    	tree[node] = arr[a]; 
		return;
	}
	
	build_tree(node*2, a, (a+b)/2);
	build_tree(node*2+1, 1+(a+b)/2, b);
	
	tree[node] = tree[node*2] + tree[node*2+1];
}
void update_tree(int node, int a, int b, int i, int j, int value) {
	int l,r;
	l=max(a,i);
	r=min(b,j);
  	if(lazy[node].val != 0) {
  		// change below line, use min & max cond
   		tree[node] += (lazy[node].val * (lazy[node].r-lazy[node].l+1));
 
		if(a != b) {
			if(lazy[node*2].val!=0) {
				tree[node*2]+=lazy[node*2].val*(lazy[node].r-lazy[node].l+1);
				lazy[node*2*2].val = lazy[node*2].val;
				lazy[node*2*2+1].val = lazy[node*2].val;
				lazy[node*2].val=0;
			}
			lazy[node*2].val = lazy[node].val;
			// lazy[node*2].r = min((lazy[node].l+lazy[node].r)/2,b);

			if(lazy[node*2+1].val!=0) {
				tree[node*2+1]+=lazy[node*2+1].val*(lazy[node].r-lazy[node].l+1);
				lazy[(node*2+1)*2].val = lazy[node*2].val;
				lazy[(node*2+1)*2+1].val = lazy[node*2].val;
				lazy[node*2+1].val=0;
			}
			lazy[node*2+1].val = lazy[node].val;
    		// lazy[node*2+1].l = max((lazy[node].l+lazy[node].r)/2+1,a);
		}
   		lazy[node].val = 0;
  	}
  
	if(a > b || a > j || b < i) return;
    
  	if(a >= i && b <= j) {
    	tree[node] += value*(r-l+1);
		if(a != b) {
			if(lazy[node*2].val!=0) {
				tree[node*2]+=lazy[node*2].val*(lazy[node].r-lazy[node].l+1);
				lazy[node*2*2].val = lazy[node*2].val;
				lazy[node*2*2+1].val = lazy[node*2].val;
			}
			lazy[node*2].val = value;
			// lazy[node*2].r = min((lazy[node].l+lazy[node].r)/2,b);

			if(lazy[node*2+1].val!=0) {
				tree[node*2+1]+=lazy[node*2+1].val*(lazy[node].r-lazy[node].l+1);
				lazy[(node*2+1)*2].val = lazy[node*2].val;
				lazy[(node*2+1)*2+1].val = lazy[node*2].val;
			}
			lazy[node*2+1].val = value;
			// lazy[node*2+1].l = max((lazy[node].l+lazy[node].r)/2+1,a);
		}
 		return;
	}
 
	update_tree(node*2, a, (a+b)/2, i, j, value);
	update_tree(1+node*2, 1+(a+b)/2, b, i, j, value);
 
	tree[node] = tree[node*2] + tree[node*2+1];
}
int query_tree(int node, int a, int b, int i, int j) {
	
	if(a > b || a > j || b < i) return 0;
 
	if(lazy[node].val != 0) {
		// use min max tp change the statement
		tree[node] += lazy[node].val * (lazy[node].r - lazy[node].l +1 );

		if(a != b) {
			if(lazy[node*2].val!=0) {
				tree[node*2]+=lazy[node*2].val*(lazy[node].r-lazy[node].l+1);
				lazy[node*2*2].val = lazy[node*2].val;
				lazy[node*2*2+1].val = lazy[node*2].val;
			}
			lazy[node*2].val=lazy[node].val;
			lazy[node*2].r = min((lazy[node].l+lazy[node].r)/2,b);

			if(lazy[node*2+1].val!=0) {
				tree[node*2+1]+=lazy[node*2+1].val*(lazy[node].r-lazy[node].l+1);
				lazy[(node*2+1)*2].val = lazy[node*2+1].val;
				lazy[(node*2+1)*2+1].val = lazy[node*2+1].val;
			}
			lazy[node*2+1].val=lazy[node].val;
			lazy[node*2+1].l = max((lazy[node].l+lazy[node].r)/2+1,a);
		}
		lazy[node].val = 0;
	}
	if(a >= i && b <= j)
		return tree[node];

	int q1 = query_tree(node*2, a, (a+b)/2, i, j);
	int q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j);

	int res = q1 + q2;
	
	return res;
}
void print() {
	int i;
	fr(i,0,MAX) pf("%d ",tree[i]);
}
int main() {
	int T,x,y,val,opt;
	for(int i = 0; i < N; i++) arr[i] = 1;
	init();
	build_tree(1, 0, N-1);
	print();
	pf("\n");
	T=100;
	while(T--) {
		sc("%d",&opt);
		if(opt==4) {
			sc("%d %d",&x,&y);
			cout<<query_tree(1,0,N-1,x-1,y-1)<<endl;
			print();
			pf("\n");
		}
		else {
			sc("%d %d %d",&x,&y,&val);
			update_tree(1,0,N-1,x-1,y-1,val);
			print();
			pf("\n");
		}
	}
	return 0;
}