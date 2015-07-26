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

struct tree {
	ll add;
	ll total;
}T[40000000];

void update(int Node,int left,int right,int i,int j,ll v) {
    if(left > j || right < i) return;
	if(left >= i && right <= j){
	    if(left != right){
            ll L = Node<<1 , R = L+1;
            T[L].add += v;
            T[R].add += v;
	    }

		T[Node].total += (right-left+1)*v;
		return;
	}

	ll mid=(left + right)>>1, L = Node<<1 , R = L+1;
    update(L,left,mid,i,j,v);
    update(R,mid+1,right,i,j,v);
	T[Node].total += v*(min(right, j)-max(left, i)+1);
}

ll query(int Node,int left,int right,int i,int j) {
    if(left > j || right < i) return 0;

    if(T[Node].add > 0){
        if(left != right){
            ll L = Node<<1 , R = L+1;
            T[L].add += T[Node].add;
            T[R].add += T[Node].add;
	    }

        T[Node].total += T[Node].add*(right-left+1);
        T[Node].add = 0;
    }

    if(left >= i && right <= j) return T[Node].total;

    ll mid = (right+left)/2, L = Node<<1 , R = L+1;
    ll ret =0;
    ret+= query(L,left,mid,i,j);
    ret+= query(R,mid+1,right,i,j);
    return ret;
}
void print() {
	int i;
	fr(i,0,16) pf("%lld ",T[i].total);
	pf("\n");
	fr(i,0,16) pf("%lld ",T[i].add);
}
int main() {
	int t,n,m,i;
	sc("%d",&t);
	while(t--){
		sc("%d %d",&n,&m);
		fr(i,0,40000000) T[i].total=T[i].add=0;
		while(m--) {
			int q,a,b;
			ll val;
			sc("%d %d %d",&q,&a,&b);
			if(!q) {
				sc("%lld",&val);
				update(1,1,n,a,b,val);
				// print();
				// pf("\n");
			}
			else {
				pf("%lld\n",query(1,1,n,a,b));
				// print();
				// pf("\n");
			}
		}
	}
	return 0;
}