#include<bits/stdc++.h>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1=0,tmp2=0,tmp3=0,tmp=0,tmp4=0,tmp5=0,flag=0,T=0,Q=0
#define pb push_back
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
using namespace std;
 
#define N 100010
#define MAX 400100
 
int arr[N];
int tree[MAX];
void init() {
	return;
}
void build_tree(int node, int a, int b) {
  	if(a > b) return;
  	
  	if(a == b) {
    	tree[node] = arr[a];
		return;
	}
	
	build_tree(node*2, a, (a+b)/2);
	build_tree(node*2+1, 1+(a+b)/2, b);
	
	tree[node] = abs(tree[node*2] + tree[node*2+1]);
}

int query_tree(int node, int a, int b, int i, int j) {
	
	if(a > b || a > j || b < i) return 0;
 
	if(a >= i && b <= j)
		return tree[node];
 
	int q1 = query_tree(node*2, a, (a+b)/2, i, j);
	int q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j);
 
	int res = abs(q1 + q2);
	
	return res;
}

int main() {
	var(int);
	int q,n;
	sc("%d %d",&n,&q);
	for(int i = 0; i < n; i++) sc("%d",&arr[i]);
	init();
	build_tree(1, 0, n-1);
	while(q--) {
		sc("%d %d",&j,&k);
		tmp=query_tree(1, 0, n-1, j-1, k-1);
		if(tmp%2) pf("Odd\n");
		else pf("Even\n");
	}
	return 0;
}