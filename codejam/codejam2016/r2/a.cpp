#include <cstdio>
#include <string>
#include <iostream>
#include <cassert>
#include <vector>

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

void printVec(vi vec) {
	var(int);
	fr(i,0,vec.size()) pf("%d",vec[i]);
}

int main() {
	var(int);
	int T;
	string inp;
	sc("%d",&T);
	int arr[26]={0};
	fr(k,1,T+1) {
		cin>>inp;
		vi vec;
		fr(i,0,26) arr[i]=0;
		fr(i,0,inp.length()) {
			arr[inp[i]-'A']++;
		}
		while(arr['Z'-'A']!=0) {
			vec.pb(0);
			arr['Z'-'A']--;
			arr['E'-'A']--;
			arr['R'-'A']--;
			arr['O'-'A']--;
		}
		// get 6
		while(arr['X'-'A']!=0) {
			vec.pb(6);
			arr['S'-'A']--;
			arr['I'-'A']--;
			arr['X'-'A']--;
		}
		// get 7
		while(arr['S'-'A']!=0) {
			vec.pb(7);
			arr['S'-'A']--;
			arr['E'-'A']--;
			arr['V'-'A']--;
			arr['E'-'A']--;
			arr['N'-'A']--;
		}
		// get 4
		while(arr['U'-'A']!=0) {
			vec.pb(4);
			arr['F'-'A']--;
			arr['O'-'A']--;
			arr['U'-'A']--;
			arr['R'-'A']--;
		}
		// get 5
		while(arr['F'-'A']!=0) {
			vec.pb(5);
			arr['F'-'A']--;
			arr['I'-'A']--;
			arr['V'-'A']--;
			arr['E'-'A']--;
		}
		// get 8
		while(arr['G'-'A']!=0) {
			vec.pb(8);
			arr['E'-'A']--;
			arr['I'-'A']--;
			arr['G'-'A']--;
			arr['H'-'A']--;
			arr['T'-'A']--;
		}
		// get 3
		while(arr['H'-'A']!=0) {
			vec.pb(3);
			arr['T'-'A']--;
			arr['H'-'A']--;
			arr['R'-'A']--;
			arr['E'-'A']--;
			arr['E'-'A']--;
		}
		// get 2
		while(arr['T'-'A']!=0) {
			vec.pb(2);
			arr['T'-'A']--;
			arr['W'-'A']--;
			arr['O'-'A']--;
		}
		// get 1
		while(arr['O'-'A']!=0) {
			vec.pb(1);
			arr['O'-'A']--;
			arr['N'-'A']--;
			arr['E'-'A']--;
		}
		// get 9
		while(arr['N'-'A']!=0) {
			vec.pb(9);
			arr['N'-'A']--;
			arr['I'-'A']--;
			arr['N'-'A']--;
			arr['E'-'A']--;
		}
		sort(vec.begin(),vec.end());
		pf("Case #%d: ",k);
		fr(i,0,vec.size()) {
			pf("%d",vec[i]);
		}
		pf("\n");
	}
	return 0;
}