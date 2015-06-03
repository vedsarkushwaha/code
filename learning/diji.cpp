#include<bits/stdc++.h>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1=0,tmp2=0,tmp3=0,tmp=0,tmp4=0,tmp5=0,flag=0,T=0,N=0,Q=0,M=0
#define pb push_back
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
#define inf 10000
using namespace std;

int main() {
	var(int);
	int src,dst;
	sc("%d",&T);
	while(T--) {
	  sc("%d %d %d %d",&N,&M,&src,&dst);
	  //pf("4");
	  vector<pair<int,int> > gp[N+1];
	  set<pair<int,int> >st;
	  set<pair<int,int> >::iterator it;
	  vi dis(N+1,inf);
	  fr(i,0,M) {
	    sc("%d %d %d",&tmp1,&tmp2,&tmp3);
	    gp[tmp1].pb(make_pair(tmp2,tmp3));
	    gp[tmp2].pb(make_pair(tmp1,tmp3));
	  }
	  dis[src]=0;
	  while(src!=dst) {
	    //pf("1 ");
	    //fflush(stdout);
	    tmp5=0;
	    fr(i,0,gp[src].size()) {
	      //pf("2");
	      //fflush(stdout);
	      if(dis[gp[src][i].first]>dis[src]+gp[src][i].second) {
		st.insert(make_pair(dis[src]+gp[src][i].second,gp[src][i].first));
		dis[gp[src][i].first]=dis[src]+gp[src][i].second;
		tmp5=1;
	      }
	    }
	    if(tmp5==0 && st.empty()) {
	      pf("NONE\n");
	      tmp5=2;
	      break;
	    }
	    //tmp5++;
	    //pf("%lu ",st.size());
	    //fflush(stdout);
	    src=(st.begin())->second;
	    st.erase(st.begin());
	  }
	  if(tmp5!=2)
	    pf("%d\n",dis[dst]);
	}
	return 0;
}
