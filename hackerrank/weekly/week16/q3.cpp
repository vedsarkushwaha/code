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

void printVec(vi &vec) {
	var(int);
	fr(i,0,vec.size()) pf("%d ",vec[i]);
}

int setSprinkles(int range, vi &pos,int n,bool p) {
	var(int);
	int cnt=0,pre=0;
	int maxLimit=range+1;
	vi plant;
	// if(pos.front()>1+range || (n-pos.back())>range) return -1;
	fr(i,0,pos.size()) {
		if(pos[i]<=maxLimit) {
			pre=i;
			continue;
		}
		// if(pos[i]>pos[pre]+2*range+1) return -1;
		cnt++;
		plant.pb(pos[pre]);
		maxLimit=pos[pre]+range*2+1;
		pre=i;
	}
	if(plant.size()!=0 && plant.back()+range<n) {
		cnt++;
		plant.pb(pos.back());
	}
	else if(plant.size()==0) {
		cnt++;
		plant.pb(pos.back());
	}
	if(p) printVec(plant);
	return cnt;
}

ll getCost(int range, int sprinkleNum, int S, int Q) {
	return (ll)sprinkleNum*S + (ll)range*Q;
}

int main() {
	var(int);
	int n,m,s,q,range,sprinkleNum=0,finRange=0,finsprinkleNum=0;
	ll gCost=INT_MAX,lCost;
	vi pos;
	sc("%d",&T);
	while(T--) {
		pos.clear();
		sc("%d %d %d %d",&n,&m,&s,&q);
		fr(i,0,m) {
			sc("%d",&tmp);
			pos.pb(tmp);
		}
		gCost=1000000000000;
		int maxdiff=0;
		fr(i,1,pos.size()) {
			tmp=pos[i]-pos[i-1]-1;
			if(tmp%2==0) tmp=tmp/2;
			else tmp=tmp/2+1;
			maxdiff=max(maxdiff,tmp);
		}
		maxdiff=max(maxdiff,pos[0]-1);
		maxdiff=max(maxdiff,n-pos.back());
		range=1;
		while(range<n) {
			sprinkleNum=setSprinkles(range,pos,n,0);
			if(sprinkleNum==-1) continue;
			lCost=getCost(range,sprinkleNum,s,q);
			if(lCost<gCost) {
				gCost=lCost;
				finRange=range;
				finsprinkleNum=sprinkleNum;
			}
			range=range*2;
		}
		pf("%d %d\n",finsprinkleNum,finRange);
		setSprinkles(finRange,pos,n,1);
		pf("\n");
	}
	return 0;
}