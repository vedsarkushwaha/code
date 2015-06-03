#include<bits/stdc++.h>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1=0,N,tmp2=0,tmp3=0,tmp=0,tmp4=0,tmp5=0,flag=0,T=0,Q=0
#define pb push_back
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
using namespace std;

double dist(pair<int,int> p1, pair<int,int> p2) {
	var(int);
	double dtmp,dtmp1;
	dtmp=(p2.first-p1.first)*(p2.first-p1.first);
	dtmp1=(p2.second-p1.second)*(p2.second-p1.second);
	return sqrt(dtmp+dtmp1);
}
pair<int,int> p0;

bool comp(pair<pair<int,int>,int> p1, pair<pair<int,int>,int> p2) {
	var(int);
	double dtmp3,dtmp4;
	tmp1=(p2.first.first-p0.first)*(p1.first.second-p0.second);
	tmp2=(p2.first.second-p0.second)*(p1.first.first-p0.first);
	if(tmp1!=tmp2)
		return tmp1<tmp2;
	else {
		dtmp4=dist(p0,p2.first);
		dtmp3=dist(p0,p1.first);
		return dtmp4<=dtmp3;
	}
}

bool chk(pair<pair<int,int>,int> p0,pair<pair<int,int>,int> p1, pair<pair<int,int>,int> p2) {
	var(int);
	tmp1=(p2.first.first-p0.first.first)*(p1.first.second-p0.first.second);
	tmp2=(p2.first.second-p0.first.second)*(p1.first.first-p0.first.first);
	return tmp1==tmp2;
}

void print(vector<pair<pair<int,int>,int> > vec) {
	var(int);
	fr(i,0,vec.size()) {
		pf("%d ",vec[i].second+1);
	}
}

void peri(vector<pair<pair<int,int>,int> > vec) {
	var(int);
	if(vec.size()<2) {
		pf("0.00");
		return;
	}
	double ans=0;
	fr(i,0,vec.size()-1) {
		tmp=vec[i].first.first-10000;
		tmp1=vec[i].first.second-10000;
		tmp2=vec[i+1].first.first-10000;
		tmp3=vec[i+1].first.second-10000;
		// pf("%d,%d\n",tmp,tmp1);
		// pf("%d,%d\n",tmp2,tmp3);
		ans+=dist(make_pair(tmp,tmp1),make_pair(tmp2,tmp3));
	}
	ans+=dist(vec[0].first,vec.back().first);
	pf("%.2lf",ans);
}

int main() {
	var(int);
	sc("%d",&T);
	while(T--) {
		vector<pair<pair<int,int>,int> > sortdel,inp;
		pair<pair<int,int>,int> p1,p2;
		sc("%d",&N);
		p0.first=INT_MAX;
		p0.second=INT_MAX;
		int ind=0;
		set<pair<int,int> >st;
		pair<set<pair<int,int> >::iterator, bool> pr;
		fr(i,0,N) {
			sc("%d %d",&tmp1,&tmp2);
			pr=st.insert(make_pair(tmp1,tmp2));
			if(!pr.second)
				continue;
			tmp1+=10000;
			tmp2+=10000;
			inp.pb(make_pair(make_pair(tmp1,tmp2),i));
			if(tmp2<p0.second) {
				p0.first=tmp1;
				p0.second=tmp2;
				ind=i;
			}
			else if(tmp2==p0.second && tmp1<p0.first) {
				p0.first=tmp1;
				p0.second=tmp2;
				ind=i;
			}
		}
		if(inp.size()<2) {
			peri(inp);
			pf("\n");
			print(inp);
			pf("\n");
			pf("\n");
			continue;
		}
		// pf("ind=%d\n",ind);
		swap(inp[ind],inp[0]);
		sort(inp.begin()+1,inp.end(),comp);
		// print(inp);
		// pf("\n");
		sortdel.pb(inp[0]);
		sortdel.pb(inp[1]);
		// pf("pp");
		// fflush(stdout);
		fr(i,2,inp.size()) {
			if(!chk(sortdel[sortdel.size()-2],sortdel[sortdel.size()-1],inp[i])) {
				sortdel.pb(inp[i]);
				// pf("%d ",i+1);
			}
			// i++;
		}
		// print(sortdel);
		// pf("\n");
		// pf("qq");
		// fflush(stdout);
		if(sortdel.size()<3) {
			peri(sortdel);
			pf("\n");
			print(sortdel);
			pf("\n");
			pf("\n");
			continue;
		}
		// print(sortdel);
		// pf("\n");
		// fflush(stdout);
		vector<pair<pair<int,int>,int> > stk;
		stk.push_back(sortdel[0]);
		stk.push_back(sortdel[1]);
		stk.push_back(sortdel[2]);
		fr(i,3,sortdel.size()) {
			int len=stk.size();
			p0=stk[len-2].first;
			p1=stk.back();
			p2=sortdel[i];
			while(!comp(p1,p2)) {
				stk.pop_back();
				p1=stk.back();
				len=stk.size();
				p0=stk[len-2].first;
			}
			stk.push_back(p2);
		}
		// pf("ss");
		// fflush(stdout);
		peri(stk);
		// pf("stk done");
		// fflush(stdout);
		pf("\n");
		print(stk);
		pf("\n");
		pf("\n");
		// pf("tt");
		// fflush(stdout);
	}
	return 0;
}