/*
ID: vedsarkushwaha
PROG: beads
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

int main() {
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
    var(int);
    string str;
   	char ch;
    fin>>N;
    fin>>str;
    int mx=0;
    str=str+str+str;
    fr(i,N,2*N) {
		ch=str[i-1];
    	ifr(j,i-1,i-N-1) {
    		if(ch=='w') ch=str[j-1];
    		if(ch!=str[j-1] && str[j-1]!='w')
    			break;
    	}
    	tmp1=i-j;
		ch=str[i];
    	fr(j,i,i+N-1) {
    		if(ch=='w') ch=str[j+1];
    		if(ch!=str[j+1] && str[j+1]!='w')
				break;
    	}
    	tmp2=j-i+1;
    	// pf("%d %d %d\n",i-N,tmp1,tmp2);
    	mx=max(mx,min(tmp1+tmp2,N));
    }
    fout<<mx<<endl;
    return 0;
}