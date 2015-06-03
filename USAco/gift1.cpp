/*
ID: vedsarkushwaha
PROG: gift1
LANG: C++
*/
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

int main() {
	var(int);
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    map<string,pair<int,int> > mp;
    vector<string>::iterator it;
    pair<int,int> pr;
    vector<string> vec;
    fin >> N;
    // cout<<"Done0"<<endl;
    string str;
    fr(i,0,N) {
    	fin>>str;
    	vec.pb(str);
    	mp[str]=make_pair(0,0);
    	// cout<<i<<endl;
    }
    // cout<<"Done"<<endl;
    // fflush(stdout);
    int total=0,give=0,receive=0;
    fr(i,0,N) {
    	fin>>str;
    	fin>>total>>tmp;
    	if(!tmp) continue;
    	give=total/tmp;
    	pr=mp[str];	
    	mp[str]=make_pair(pr.first+give*tmp,pr.second);
    	fr(j,0,tmp) {
    		fin>>str;
    		pr=mp[str];
    		pr.second+=give;
    		mp[str]=make_pair(pr.first,pr.second);
    	}
    	// for(it=vec.begin();it!=vec.end();++it) {
    	// 	fout<<*it<<" "<<mp[*it].second-mp[*it].first<<endl;
    	// }
  		// fout<<endl;
    }
	// fout<<endl;
    for(it=vec.begin();it!=vec.end();++it) {
    	// fout<<*it<<" "<<mp[*it].first<<" "<<mp[*it].second<<endl;
    	fout<<*it<<" "<<mp[*it].second-mp[*it].first<<endl;
    }
    return 0;
}