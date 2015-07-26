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

ll arr[N+1];
ll tree[MAX];
pair<ll,ll> lazy[MAX];

void init(ll n) {
	var(ll);
	fr(i,0,4*n) {
		lazy[i].first=1;
		lazy[i].second=0;
		tree[i]=0;
	}
}

void build_tree(ll node, ll a, ll b) {
  	if(a > b) return;
  	if(a == b) { 
    	tree[node] = arr[a];
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
	var(ll);
	ll n,q,opr,x,y,v;
	sc("%lld %lld",&n,&q);
	fr(i,1,n+1) sc("%lld",&arr[i]);
	init(n);
	build_tree(1, 1, n);
	while(q--) {
		sc("%lld",&opr);
		if(opr==4) {
			sc("%lld %lld",&x,&y);
			pf("%lld\n",query_tree(1,1,n,x,y));
			// print(n);
			// pf("\n");
		}
		else {
			sc("%lld %lld %lld",&x,&y,&v);
			update_tree(1,1,n,x,y,v,opr);
			// print(n);
			// pf("\n");
		}
	}
	return 0;
}