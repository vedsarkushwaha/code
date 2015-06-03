/*
ID: vedsarkushwaha
PROG: friday
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
int inc(int tmp) {
	if(tmp<=6) return tmp+1;
	else return 1;
}
bool chk_leap(int year) {
	if(year%4==0) {
		if(year%100==0 && year%400==0) return 1;
		else if(year%100!=0) return 1;
		else return 0;
	}
	else return 0;
}
int main() {
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    var(int);
    int cnt[8]={0};
    int year=1900,month=1,day=1;
    fin>>N;
    tmp=1;
    while(year!=1900+N-1 || month!=12 || day!=31) {
    	// cout<<year<<" "<<month<<" "<<day<<" "<<tmp<<endl;
    	day++;
    	tmp=inc(tmp);
    	if(day==31) {
    		if(month==9 ||month==4||month==6||month==11) {
    			month++;
    			day=1;
    		}
    	}
    	else if(day==32) {
    		if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12) {
    			month++;
    			day=1;
    		}
    	}
    	if(month==2 && day==29) {
    		if(!chk_leap(year)) {
    			day=1;
    			month++;
    		}
    	}
    	if(month==2 && day==30) {
    		if(chk_leap(year)) {
    			day=1;
    			month++;
    		}
    	}
    	if(month==13) {
    		year++;
    		month=1;
    	}
    	if(day==13) {
    		// fout<<"e";
    		cnt[tmp]++;
    	}
    }
    fout<<cnt[6]<<" "<<cnt[7]<<" ";
    fr(i,1,6) {
    	if(i==5)
    		fout<<cnt[i]<<endl;
    	else
    		fout<<cnt[i]<<" ";
    }
    return 0;
}