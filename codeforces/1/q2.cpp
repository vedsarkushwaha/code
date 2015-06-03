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
string arr="xABCDEFGHIJKLMNOPQRSTUVWXYZ";
string get_char(ll num) {
	var(ll);
	tmp=0;
	vi vec;
	string str;
	while(num) {
		vec.pb(num%26);
		num=num/26;
	}
	//reverse(str.begin(),str.end());
	str[0]-=1;
	return str;
}
ll get_num(string str) {
	var(ll);
	reverse(str.begin(),str.end());
	tmp=0;
	while(i<str.length()) {
		tmp+=(str[i]-'A'+1)*int(pow(26,i));
		i++;
	}
	return tmp;
}
int chkstr(string str) {
	var(int);
	tmp1=-1,tmp2=-1;
	while(i<str.length()) {
		if(str[i]=='R')
			tmp1=i;
		if(str[i]=='C')
			tmp2=i;
		i++;
	}
	if(tmp1!=-1 && tmp2!=-1 && tmp2-tmp1>1) {
		// pf("Enterif");		
		fr(i,tmp1+1,tmp2) {
			if(str[i]<'0' || str[i]>'9') {
				// pf("Enterfr");
				tmp5=1; 
			}
		}
	}
	else
		return 0;
	if(tmp5==1)
		return 0;
	return 1;
}
int main() {
	string str;
	var(int);
	sc("%d",&T);
	while(T--) {
		cin>>str;
		if(chkstr(str)) {
			//R C format
			printf("\nRC\n");
			i=1;
			tmp=0;
			while(str[i]<='9' && str[i]>='0') {
				tmp=tmp*10+(str[i]-'0');
				i++;
			}
			tmp1=0;
			i++;
			while(str[i]<='9' && str[i]>='0') {
				tmp1=tmp1*10+(str[i]-'0');
				i++;
			}
			cout<<get_char(tmp1)<<tmp<<endl;
		}
		else {
			//excel format
			printf("\nexcel\n");

			string tmp3;
			i=0;
			while(str[i]<='Z' && str[i]>='A') {
				tmp3+=str[i];
				i++;
			}
			tmp4=0;
			while(str[i]<='9' && str[i]>='0') {
				tmp4=tmp4*10+(str[i]-'0');
				i++;
			}
			cout<<'R'<<tmp4<<'C'<<get_num(tmp3)<<endl;
		}
	}
	return 0;
}
