#include<cstdio>
#include<iostream>
#include<vector>
#include<stack>
#include<map>
#include<set>
#include<cstring>
#include<cmath>
#include<string>
#include<cstdlib>
#include<queue>
#include<algorithm>
#include<climits>
#include<list>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1,tmp2,tmp3,tmp=0
using namespace std;

int main() {
	var(int);
	int T,N;
	list<pair<string,string> > lst;
	list<pair<string,string> >::iterator it;
	map<string,string> mp,mp1;
	map<string,string>::iterator mpit;
	pair<string,string> pr,pr1;
	string str1,str2;
	sc("%d",&T);
	fr(i,1,T+1) {
		sc("%d",&N);
		fr(j,0,N) {
			cin>>str1;
			cin>>str2;
			mp.insert(make_pair(str1,str2));
			mp1.insert(make_pair(str2,str1));
		}
		//pf("map\n");
		//for(mpit=mp.begin();mpit!=mp.end();mpit++)
			//cout<<mpit->first<<"-"<<mpit->second<<endl;
		mpit=mp.begin();
		pr=(*mpit);
		lst.push_back(pr);
		//mp.erase(mpit);
		//mp1.erase(mpit->second);
		while((mpit=mp.find(pr.second))!=mp.end()) {
			pr=(*mpit);
			lst.push_back(pr);
			//mp.erase(mpit);
			//mp1.erase(mpit->second);
		}
		//pf("map\n");
		//for(mpit=mp.begin();mpit!=mp.end();mpit++)
			//cout<<mpit->first<<"-"<<mpit->second<<endl;
		//for(it=lst.begin();it!=lst.end();++it) {
			//cout<<it->first<<"-"<<it->second<<" ";
		//}
		//cout<<endl;
		it=lst.begin();
		//lst.push_front(*pr);
		//mp.erase(pr);
		pr=(*it);
		while((mpit=mp1.find(pr.first))!=mp1.end()) {
			pr=(*mpit);
			//pf("enter");
			pr=make_pair(pr.second,pr.first);
			lst.push_front(pr);
			//mp1.erase(mpit);
			//mp.erase(mpit->second);
		}
		//pf("map\n");
		//for(mpit=mp.begin();mpit!=mp.end();mpit++)
			//cout<<mpit->first<<"-"<<mpit->second<<endl;
		//print the lst
		pf("Case #%d: ",i);
		for(it=lst.begin();it!=lst.end();++it) {
			cout<<it->first<<"-"<<it->second<<" ";
		}
		cout<<endl;
		lst.clear();
		mp.clear();
		mp1.clear();
	}
	return 0;
}
