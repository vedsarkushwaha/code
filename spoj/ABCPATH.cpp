#include<bits/stdc++.h>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1=0,tmp2=0,tmp3=0,tmp=0,tmp4=0,tmp5=0,flag=0,T=0,N=0,l
#define pb push_back
using namespace std;
pair<char,int> grd[100][100];
int maxch;
int fun(int p,int q,char ch) {
  var(int);
  fr(i,-1,2) {
    fr(j,-1,2) {
      if(grd[p+i][q+j].first==ch && grd[p+i][q+j].second==0) {
      	grd[p+i][q+j].second=1;
      	maxch=max(maxch,ch-'A'+1);
        fun(p+i,q+j,ch+1);
      }
    }
  }
  return maxch;
}
int main() {
	var(int);
	int H,W;
	char ch;
	while(1) {
		sc("%d %d",&H,&W);
		if(H==0 && W==0)
			break;
		maxch=0;
		fr(i,0,H+2) {
			fr(j,0,W+2) {
			  if(i==0 || j==0 || i==H+1 || j==W+1) {
			    grd[i][j].first='#';
		    }
		    else {
			    sc("%c",&ch);
			    grd[i][j].first=ch;
		    }
		    grd[i][j].second=0;
	    }
	    if(i!=H+1) sc("%c",&ch);
    }
    ch='A';
		fr(i,1,H+1) {
		  fr(j,1,W+1) {
		    if(grd[i][j].first==ch) {
		      grd[i][j].second=1;
		      fun(i,j,ch+1);
  		  }
		  }
	  }
		pf("Case %d: %d\n",++tmp1,maxch);
	}
	return 0;
}
