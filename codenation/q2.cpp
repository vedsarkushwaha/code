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
int mx=0;
void lcs( string X, string Y,string Z) {
	var(int);
	int m=X.length(),n=Y.length();
	int L[m+1][n+1];
	fr(i,0,m+1) {
		fr(j,0,n+1) {
			if (i == 0 || j == 0)
				L[i][j] = 0;
			else if (X[i-1] == Y[j-1])
				L[i][j] = L[i-1][j-1] + 1;
			else
				L[i][j] = max(L[i-1][j], L[i][j-1]);
		}
	}
	int index = L[m][n];
	char lcs[index+1];
	lcs[index] = '\0';
	tmp=index;
	i = m, j = n;
	while (i > 0 && j > 0) {
		if(X[i-1]==Y[j-1]) {
			lcs[index-1] = X[i-1];
			i--;j--;index--;
		}
		else if (L[i-1][j] > L[i][j-1])
			i--;
		else
			j--;
	}
	string str;
	fr(i,0,tmp) {
		str+=lcs[i];
	}
	//pf("%s\n",lcs);
	mx=max(mx,str.length());
}

int main() {
	var(int);
	string str1,str2,str3,tmpstr1,tmpstr2,tmpstr3;
	cin>>str1;
	cin>>str2;
	cin>>str3;
	fr(j,1,str3.length()+1) {
		fr(i,0,str3.length()) {
			if(str1.find(str3[i])!=string::npos && str2.find(str3[i])!=string::npos) {
				while(str1.find(str3[i])!=string::npos && str2.find(str3[i])!=string::npos) {
					str1.erase(str1.find(str3[i]),1);str2.erase(str2.find(str3[i]),1);
				}
				break;
			}
		}
	}
	//cout<<str1<<' '<<str2<<endl;
	lcs(str1,str2,str3);
	return 0;
}
