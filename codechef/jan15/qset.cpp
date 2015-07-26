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
#define md 1000000007
#define N 100010
#define MAX 4*N

struct node {
	int val,cnt0,cnt1,cnt2;
};

int arr[N+1];
node tree[MAX];
int lazy[MAX];

void init(int n) {
	var(int);
	fr(i,0,4*n) {
		lazy[i]=0;
		tree[i].val=0;
		tree[i].cnt0=0;
		tree[i].cnt1=0;
		tree[i].cnt2=0;
	}
}

void build_tree(int node,int a,int b) {
  	if(a>b) return;
  	if(a==b) {
    	tree[node].val=arr[a].val;
    	if(arr[a].val==0) tree[node].cnt0=1;
    	else if(arr[a].val==0) tree[node].cnt1=1;
    	else if(arr[a].val==0) tree[node].cnt2=1;
		return;
	}
	build_tree(node*2, a, (a+b)/2);
	build_tree(node*2+1, 1+(a+b)/2, b);
	tree[node] = (tree[node*2] + tree[node*2+1])%md;
}

void update_tree(ll node, ll a, ll b, ll i, ll j, ll value, ll opr) {
	tree[node] = (tree[node]*lazy[node].first + lazy[node].second * (b-a+1))%md;
	if(a!=b) {
		lazy[node*2].first = (lazy[node*2].first * lazy[node].first)%md;
		lazy[node*2].second = (lazy[node*2].second * lazy[node].first)%md;
		lazy[node*2].second = (lazy[node*2].second + lazy[node].second)%md;

		lazy[node*2+1].first = (lazy[node*2+1].first * lazy[node].first)%md;
		lazy[node*2+1].second = (lazy[node*2+1].second * lazy[node].first)%md;
		lazy[node*2+1].second = (lazy[node*2+1].second + lazy[node].second)%md;
	}
	lazy[node].first=1;
	lazy[node].second=0;

	if(a > b || a > j || b < i) return;
  	
  	if(a >= i && b <= j) {
  		if(opr==1) {
	    	tree[node] = (tree[node]+ (value * ( min(b,j) - max(a,i) + 1 )))%md;
	    	if(a!=b) {
				lazy[node*2].second = (lazy[node*2].second+value)%md;
				lazy[node*2+1].second = (lazy[node*2+1].second+value)%md;
			}
		}
		else if(opr==2) {
			tree[node] = (tree[node] * value)%md;
			if(a!=b) {
				lazy[node*2].first = (lazy[node*2].first * value)%md;
				lazy[node*2].second = (lazy[node*2].second * value)%md;
				lazy[node*2+1].first = (lazy[node*2+1].first * value)%md;
				lazy[node*2+1].second = (lazy[node*2+1].second * value)%md;
			}
		}
		else if(opr==3) {
			tree[node] = (value * ( min(b,j) - max(a,i) + 1 ))%md;
			if(a!=b) {
				lazy[node*2].first = 0;
				lazy[node*2].second = value;
				lazy[node*2+1].first = 0;
				lazy[node*2+1].second = value;
			}
		}
		return;
	}
	// else part, if  "if part" not executed
	update_tree(node*2, a, (a+b)/2, i, j, value, opr);
	update_tree(1+node*2, 1+(a+b)/2, b, i, j, value, opr);
	tree[node] = (tree[node*2] + tree[node*2+1])%md;
}

ll query_tree(ll node, ll a, ll b, ll i, ll j) {
	
	if(a > b || a > j || b < i) return 0;
 
	tree[node] = (tree[node]*lazy[node].first + lazy[node].second * (b-a+1))%md;
	if(a!=b) {
		lazy[node*2].first = (lazy[node*2].first * lazy[node].first)%md;
		lazy[node*2].second = (lazy[node*2].second * lazy[node].first)%md;
		lazy[node*2].second = (lazy[node*2].second + lazy[node].second)%md;

		lazy[node*2+1].first = (lazy[node*2+1].first * lazy[node].first)%md;
		lazy[node*2+1].second = (lazy[node*2+1].second * lazy[node].first)%md;
		lazy[node*2+1].second = (lazy[node*2+1].second + lazy[node].second)%md;
	}
	lazy[node].first=1;
	lazy[node].second=0;

	if(a >= i && b <= j) return tree[node];
 
	ll q1 = query_tree(node*2, a, (a+b)/2, i, j);
	ll q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j);
 
	return (q1 + q2)%md;
}

void print(int n) {
	int i;
	fr(i,1,4*n) pf("%lld ",tree[i]);
	pf("\n");
	fr(i,1,4*n) pf("%lld ",lazy[i].second);
	pf("\n");
}

int main() {
	var(int);
	int n,m,q,opr,x,y,v;
	sc("%d %d",&n,&m);
	arr[0]=0;
	fr(i,1,n+1) {
		sc("%d",&tmp);
		arr[i]=(tmp+arr[i-1])%3;
	}
	init(n);
	build_tree(1, 1, n);
	while(m--) {
		sc("%d %d %d",&opr,&x,&y);
		if(opr==1) {
			// update
			// pf("%lld\n",query_tree(1,1,n,x,y));
			// print(n);
			// pf("\n");
		}
		else {
			// query
			// update_tree(1,1,n,x,y,v,opr);
			// print(n);
			// pf("\n");
		}
	}
	return 0;
}