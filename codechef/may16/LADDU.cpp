#include <iostream>
#include <cstdio>
#include <cassert>

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
	sc("%d",&T);
	while(T--) {
		int activities;
		string origin;
		cin>>activities>>origin;
		int score=0;
		while(activities--) {
			string objActivity;
			int rank;
			cin>>objActivity;
			// cout<<objActivity<<endl;
			if(objActivity.compare("CONTEST_WON") == 0) {
				cin>>rank;
				score+=(300+max(0,20-rank));
			}
			else if(objActivity.compare("TOP_CONTRIBUTOR") == 0) {
				score+=300;
			}
			else if(objActivity.compare("BUG_FOUND") == 0) {
				cin>>rank;
				score+=rank;
			}
			else if(objActivity.compare("CONTEST_HOSTED") == 0) {
				score+=50;
			}
			else assert(1==0);
		}
		if(origin == "INDIAN") {
			pf("%d\n",score/200);
		}
		else if(origin == "NON_INDIAN") {
			pf("%d\n",score/400);
		}
		else assert(1==0);
	}
	return 0;
}
