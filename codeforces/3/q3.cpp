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
	string str[3];
	cin>>str[0]>>str[1]>>str[2];
	// pf("%d",tmp5);
	fr(i,0,3) {
		fr(j,0,3) {
			if(str[i][j]=='X') tmp1++;
			if(str[i][j]=='0') tmp2++;
			if(str[i][j]=='.') tmp3=1;
		}
	}
	if(tmp1-tmp2!=0 && tmp1-tmp2!=1) {
		pf("illegal");
		return 0;
	}
	fr(i,0,3) {
		if(str[i][0]==str[i][1] && str[i][1]==str[i][2] && str[i][0]!='.') {
			if(str[i][0]=='X')
				tmp4+=1;
			else
				tmp5+=1;
		}
		if(str[0][i]==str[1][i] && str[1][i]==str[2][i] && str[0][i]!='.') {
			if(str[i][0]=='X')
				tmp4+=1;
			else
				tmp5+=1;
		}
	}
	if(str[0][0]==str[1][1] && str[2][2]==str[1][1] && str[0][0]!='.') {
		if(str[0][0]=='X')
			tmp4+=1;
		else
			tmp5+=1;
	}
	if(str[0][2]==str[1][1] && str[2][0]==str[1][1] && str[2][0]!='.') {
		if(str[0][2]=='X')
			tmp4+=1;
		else
			tmp5+=1;
	}
	// pf("%d",tmp5);

	if(tmp5>1 || tmp4>1) {
		pf("illegal");
		return 0;
	}
	else if(tmp4==tmp5 && tmp4==1) {
		pf("illegal");
		return 0;
	}
	else if(tmp4==1) {
		pf("the first player won");
		return 0;
	}
	else if(tmp5==1) {
		pf("the second player won");
		return 0;
	}

	if(!tmp3) {
		pf("draw");
	}
	else if(tmp1-tmp2==1)
		pf("second\n");
	else if(tmp2==tmp1)
		pf("first\n");
	else
		pf("wrong");
	return 0;
}