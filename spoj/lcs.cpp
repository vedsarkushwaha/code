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
	int inpArr[26]={0},inpSubstr[26][26]={0};
	int localLen=0,globalLen=0;
	var(int);
	fr(i,0,26) fr(j,0,26) assert(inpSubstr[i][j]==0);
	string inp1,inp2;
	cin>>inp1>>inp2;
	fr(i,0,inp1.length()) {
		inpArr[inp1[i]-'a']=1;
		if(i!=inp1.length()-1) inpSubstr[inp1[i]-'a'][inp1[i+1]-'a']=1;
	}
	// fr(i,0,26) {
	// 	fr(j,0,26) {
	// 		pf("%d ",inpSubstr[i][j]);
	// 	}
	// 	pf("\n");
	// }
	// pf("\n");
	fr(i,0,inp2.length()-1) {
		if(!localLen && inpArr[inp2[i]-'a']) localLen=1;
		if(inpSubstr[inp2[i]-'a'][inp2[i+1]-'a']) localLen++;
		else {
			globalLen=max(globalLen,localLen);
			localLen=0;
		}
		pf("%c %d\n",inp2[i],localLen);
	}
	pf("%d",globalLen);
	return 0;
}