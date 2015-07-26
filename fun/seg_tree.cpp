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
 
#define N 4
#define MAX (1+(1<<3)) // Why? :D
#define inf 0x7fffffff
 
int arr[N];
int tree[MAX];
int lazy[MAX];

void build_tree(int node, int a, int b) {
  	if(a > b) return; // Out of range
  	
  	if(a == b) { // Leaf node
    		tree[node] = arr[a]; // Init value
		return;
	}
	
	build_tree(node*2, a, (a+b)/2); // Init left child
	build_tree(node*2+1, 1+(a+b)/2, b); // Init right child
	
	tree[node] = max(tree[node*2], tree[node*2+1]); // Init root value
}
 
/**
 * Increment elements within range [i, j] with value value
*/
void update_tree(int node, int a, int b, int i, int j, int value) {
  
  	if(lazy[node] != 0) { // This node needs to be updated
   		tree[node] += lazy[node]; // Update it
 
		if(a != b) {
			lazy[node*2] += lazy[node]; // Mark child as lazy
    			lazy[node*2+1] += lazy[node]; // Mark child as lazy
		}
 
   		lazy[node] = 0; // Reset it
  	}
  
	if(a > b || a > j || b < i) // Current segment is not within range [i, j]
		return;
    
  	if(a >= i && b <= j) { // Segment is fully within range
    		tree[node] += value;
 
		if(a != b) { // Not leaf node
			lazy[node*2] += value;
			lazy[node*2+1] += value;
		}
 
    		return;
	}
 
	update_tree(node*2, a, (a+b)/2, i, j, value); // Updating left child
	update_tree(1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child
 
	tree[node] = max(tree[node*2], tree[node*2+1]); // Updating root with max value
}
 
/*
 * Query tree to get max element value within range [i, j]
**/
int query_tree(int node, int a, int b, int i, int j) {
	
	if(a > b || a > j || b < i) return -inf; // Out of range
 
	if(lazy[node] != 0) { // This node needs to be updated
		tree[node] += lazy[node]; // Update it

		if(a != b) {
			lazy[node*2] += lazy[node]; // Mark child as lazy
			lazy[node*2+1] += lazy[node]; // Mark child as lazy
		}

		lazy[node] = 0; // Reset it
	}
 
	if(a >= i && b <= j) // Current segment is totally within range [i, j]
		return tree[node];
 
	int q1 = query_tree(node*2, a, (a+b)/2, i, j); // Query left child
	int q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child
 
	int res = max(q1, q2); // Return final result
	
	return res;
}

void print(int n) {
	int i;
	fr(i,0,4*n) pf("%d ",tree[i]);
	pf("\n");
}

int main() {
	for(int i = 0; i < N; i++) arr[i] = 1;
	build_tree(1, 0, N-1);
	print(N);
	pf("\n");
	memset(lazy, 0, sizeof(lazy));
	int t=100;
	int x,y,val,opt;
	while(t--) {
		sc("%d",&opt);
		if(opt==1) {
			sc("%d %d %d",&x,&y,&val);
			update_tree(1, 1, N, x, y, val);
			print(N);
			pf("\n");
		}
		else {
			sc("%d %d",&x,&y);
			cout << query_tree(1, 1, N, x, y) << endl;
			print(N);
			pf("\n");
		}
	}
}