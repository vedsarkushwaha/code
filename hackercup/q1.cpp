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
vii vec;
bool cmp2(pair<char,int> p1,pair<char,int> p2) {
	if(p1.first<p2.first)
		return true;
	else if(p1.first>p2.first)
		return false;
	else {
		if(p1.second>p2.second)
			return true;
		else
			return false;
	}
}
void get_digit(string str) {
	var(int);
	vec.clear();
	fr(i,0,str.size()) {
		if(str[i]=='0')
			continue;
		vec.pb(make_pair(str[i],i));
	}
}
int main() {
	var(ll);
	pair<char,int> pttmp;
	string str,str1;
	sc("%lld",&T);
	fr(tmp3,1,T+1) {
		cin>>str;
		str1=str;
		k=0;
		get_digit(str);
		sort(vec.begin(),vec.end(),cmp2);
		//fr(i,0,vec.size())
			//pf("%c-%d\n",vec[i].first,vec[i].second);
		//chk zero
		ifr(i,str.length()-1,0) {
			if(str[i]=='0') {
				fr(j,1,i) {
					if(str[j]!='0') {
						swap(str[j],str[i]);
						k=1;
						break;
					}
				}
			}
			if(k) {
				cout<<"Case #"<<tmp3<<":"<<' '<<str<<' ';
				break;
			}
		}
		if(!k) {
			fr(i,0,vec.size()) {
				pttmp=vec[i];
				fr(j,0,pttmp.second) {
					if(str[j]>pttmp.first) {
						swap(str[pttmp.second],str[j]);
						k=1;
						break;
					}
				}
				if(k) {
					cout<<"Case #"<<tmp3<<":"<<' '<<str<<' ';
					break;
				}	
			}
		}
		if(!k) {
			cout<<"Case #"<<tmp3<<":"<<' '<<str<<' ';
		}
		str=str1;
		//cout<<str<<endl;	
		k=0;
		/*pf("vec size %d ",vec.size());
		ifr(i,vec.size()-1,-1) {
			pf("%c-%d ",vec[i].first,vec[i].second);
		}*/
		//pf("\n");
		sort(vec.begin(),vec.end());
		ifr(i,vec.size()-1,-1) {
			pttmp=vec[i];
			fr(j,0,pttmp.second) {
				if(str[j]<pttmp.first) {
					swap(str[pttmp.second],str[j]);
					k=1;
					break;
				}
			}
			if(k) {
				cout<<str<<endl;
				break;
			}	
		}
		if(!k) {
			cout<<str<<endl;
		}
	}
	return 0;
}
