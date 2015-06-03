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
	string str1,str2;
	cin>>str1;
	cin>>str2;
	char ch;
	sc("%c",&ch);
	tmp1=str1[0]-str2[0];
	tmp2=str1[1]-str2[1];
	string vmove,hmove;
	if(tmp1<0) {
		while(tmp1!=0) {
			hmove+='R';
			tmp1++;
		}
	}
	else {
		while(tmp1!=0) {
			hmove+='L';
			tmp1--;
		}
	}
	if(tmp2<0) {
		while(tmp2!=0) {
			vmove+='U';
			tmp2++;
		}
	}
	else {
		while(tmp2!=0) {
			vmove+='D';
			tmp2--;
		}
	}
	k=0;
	if(vmove.size()>hmove.size()) {
		pf("%lu\n",vmove.size());
		fr(i,0,hmove.size()) {
			if(k==vmove.size())
				pf("%c%c",hmove[i],vmove[i]);
			else
				pf("%c%c\n",hmove[i],vmove[i]);
			k++;
		}
		while(i<=vmove.size()) {
			if(k==vmove.size())
				pf("%c",vmove[i]);
			else
				pf("%c\n",vmove[i]);
			i++;
			k++;
		}
	}
	else {
		pf("%lu\n",hmove.size());
		fr(i,0,vmove.size()) {
			if(k==hmove.size()) {
				pf("%c%c",hmove[i],vmove[i]);
			}
			else
				pf("%c%c\n",hmove[i],vmove[i]);
			k++;
		}
		while(i<=hmove.size()) {
			if(k==hmove.size())
				pf("%c",hmove[i]);
			else
				pf("%c\n",hmove[i]);
			k++;
			i++;
		}
	}
	return 0;
}