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

pair<ll,ll> fun(ll x, ll n) {
    var(ll);
    tmp = 6*x - n + n*n*n;
    if(tmp==0) return make_pair(-1,-1);
    // assert(tmp%3==0);
    if(tmp%3) return make_pair(-1,-1);
    tmp/=3;
    // assert(tmp%n==0);
    if(tmp%n) return make_pair(-1,-1);
    tmp/=n;
    // assert(tmp%(n+1)==0);
    if(tmp%(n+1)) return make_pair(-1,-1);
    tmp/=(n+1);
    if(n>tmp) return make_pair(-1,-1);
    return make_pair(n,tmp);
    // return n and calculated m,
}
int main() {
    var(ll);
    ll x;
    pair<ll,ll> pr;
    cin>>x;
    vll ans;
    double lp=pow(x,0.34);
    fr(i,1,lp*2+1) {
        pr=fun(x,i);
        if(pr.first!=-1) ans.pb(pr);
    }
    if(ans.size()==0) {
        pf("Empty");
        return 0;
    }
    if(ans.back().first==ans.back().second) {
        pf("%d\n",2*ans.size()-1);
        fr(i,0,ans.size()) {
            cout<<ans[i].first<<" "<<ans[i].second<<endl;
        }
        if(ans.size()>1)
        ifr(i,ans.size()-2,-1) {
            cout<<ans[i].second<<" "<<ans[i].first<<endl;
        }
    }
    else {
        pf("%d\n",2*ans.size());
        fr(i,0,ans.size()) {
            cout<<ans[i].first<<" "<<ans[i].second<<endl;
        }
        ifr(i,ans.size()-1,-1) {
            cout<<ans[i].second<<" "<<ans[i].first<<endl;
        }
    }
    return 0;
}