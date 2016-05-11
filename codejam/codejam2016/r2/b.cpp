#include <cstdio>
#include <string>
#include <iostream>
#include <cassert>

#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1=0,tmp2=0,tmp3=0,tmp=0,tmp4=0,tmp5=0,flag=0
#define pb push_back
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
using namespace std;

int main() {
	string coder, jammer;
	var(int);
	int T;
	sc("%d",&T);
	fr(j,1,T+1) {
		cin>>coder>>jammer;
		int N=coder.length();
		flag=0;
		fr(i,0,N) {
			if(flag==0) {
				if(coder[i]=='?' && jammer[i]=='?') {
					tmp = coder[i+1]-'0';
					tmp1 = jammer[i+1]-'0';
					if(i!=N-1 && (coder[i+1]!='?' && jammer[i+1]!='?') && (abs(tmp-tmp1)>5)) {
						if(coder[i+1]>jammer[i+1]) {
							coder[i]='0';
							jammer[i]='1';
							flag=1;
						}
						else {
							coder[i]='1';
							jammer[i]='0';
							flag=2;
						}
					}
					else {
						coder[i]='0';
						jammer[i]='0';
					}
				}
				else if(coder[i]=='?' && jammer[i]!='?') {
					coder[i]=jammer[i];
				}
				else if(coder[i]!='?' && jammer[i]=='?') {
					jammer[i]=coder[i];
				}
				else {
					assert(coder[i]!='?' && jammer[i]!='?');
					if(coder[i]<jammer[i]) flag=1;
					else if(coder[i]>jammer[i]) flag=2;
				}
			}
			else if(flag==1) {
				if(coder[i]=='?') coder[i]='9';
				if(jammer[i]=='?') jammer[i]='0';
			}
			else if(flag==2) {
				if(coder[i]=='?') coder[i]='0';
				if(jammer[i]=='?') jammer[i]='9';
			}
			else {
				assert(1==0);
			}
		}
		cout<<"Case #"<<j<<": "<<coder<<" "<<jammer<<endl;
	}
	return 0;
}