/*
ID: vedsarkushwaha
PROG: ride
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
ll md=47;
using namespace std;
int chk(string str1,string str2) {
	var(ll);
	tmp=1;
	fr(i,0,str1.length()) {
		tmp=((tmp*(str1[i]-'A'+1))%md);
	}
	tmp1=1;
	fr(i,0,str2.length()) {
		tmp1=((tmp1*(str2[i]-'A'+1))%md);
	}
	// pf("%d %d\n",tmp,tmp1);
	if(tmp1==tmp) return 1;
	else return 0;
}
int main() {
	ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string str1,str2;
    fin>>str1;
    fin>>str2;
    if(chk(str1,str2))
    	fout<<"GO"<<endl;
    else
    	fout<<"STAY"<<endl;
    return 0;
}