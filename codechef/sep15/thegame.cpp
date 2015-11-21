#include<bits/stdc++.h>
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

void printVec(vector<complex<double> > &vec) {
  var(int);
  fr(i,0,vec.size()) {
    pf("%lf %lf\n",vec[i].real(),vec[i].imag());
  }
  pf("\n");
}

vector<complex<double> > fft(const vector<complex<double> > &as) {
  int n = as.size();
  int k = 0;
  while ((1 << k) < n) k++;
  vector<int> rev(n);
  rev[0] = 0;
  int high1 = -1;
  for (int i = 1; i < n; i++) {
    if ((i & (i - 1)) == 0)
      high1++;
    rev[i] = rev[i ^ (1 << high1)];
    rev[i] |= (1 << (k - high1 - 1));
  }

  vector<complex<double> > roots(n);
  for (int i = 0; i < n; i++) {
    double alpha = 2 * M_PI * i / n;
    roots[i] = complex<double>(cos(alpha), sin(alpha));
  }

  vector<complex<double> > cur(n);
  for (int i = 0; i < n; i++)
    cur[i] = as[rev[i]];

  for (int len = 1; len < n; len <<= 1) {
    vector<complex<double> > ncur(n);
    int rstep = roots.size() / (len * 2);
    for (int pdest = 0; pdest < n;) {
      int p1 = pdest;
      for (int i = 0; i < len; i++) {
        complex<double> val = roots[i * rstep] * cur[p1 + len];
        ncur[pdest] = cur[p1] + val;
        ncur[pdest + len] = cur[p1] - val;
        pdest++, p1++;
      }
      pdest += len;
    }
    cur.swap(ncur);
  }
  return cur;
}

vector<complex<double> > fft_rev(const vector<complex<double> > &as) {
  vector<complex<double> > res = fft(as);
  for (int i = 0; i < (int)res.size(); i++) res[i] /= as.size();
  reverse(res.begin() + 1, res.end());
  return res;
}

vector<complex<double> > prodPoly(vector<complex<double> > &pol1,vector<complex<double> > &pol2) {
  // index 0 should contain lowest degree coeff
  int n1,n2,deg,ans_deg;
  var(int);
  vector<complex<double> > dft1,dft2,ans;
  n1=pol1.size();
  n2=pol2.size();
  ans_deg=n1+n2-1;
  deg=max(n1,n2);
  deg=pow(2,ceil(log2(deg)));
  fr(i,n1,2*deg) {
    pol1.pb(complex<double>(0.0,0.0));
  }
  fr(i,n2,2*deg) {
    pol2.pb(complex<double>(0.0,0.0));
  }

  dft1=fft(pol1);
  dft2=fft(pol2);

  printVec(dft1);
  
  fr(i,0,dft1.size()) {
    ans.pb(dft1[i]*dft2[i]);
  }
  ans=fft_rev(ans);
  pf("%d\n",ans_deg);
  ans.erase(ans.begin()+ans_deg,ans.end());
  return ans;
}

int main() {
	int T,R,C;
	var(int);
	char ch;
	sc("%d",&T);
	while(T--) {
		sc("%d %d",&R,&C);
		char game[R+2][C+2];
		fr(i,0,R+1) {
			if(i!=0) sc("%c",&ch);
			fr(j,0,C+1) {
				if(i==0 || j==0 || i==R+1 || j==C+1) game[i][j]='#';
				else {
					sc("%c",&ch);
					game[i][j]=ch;
				}
			}
		}
		vi cncmpt;
		// BFS
		fr(i,1,R+1) {
			fr(j,1,C+1) {
				int cnt=0;
				if(game[i][j]=='o') {
					stack<pair<int,int> >stk;
					pair<int,int> temp;
					stk.push(make_pair(i,j));
					while(!stk.empty()) {
						cnt++;
						temp=stk.top();
						game[temp.first][temp.second]='#';
						stk.pop();
						if(game[temp.first][temp.second+1]=='o') {stk.push(make_pair(temp.first,temp.second+1));game[temp.first][temp.second+1]='#';}
						if(game[temp.first][temp.second-1]=='o') {stk.push(make_pair(temp.first,temp.second-1));game[temp.first][temp.second-1]='#';}
						if(game[temp.first+1][temp.second]=='o') {stk.push(make_pair(temp.first+1,temp.second));game[temp.first+1][temp.second]='#';}
						if(game[temp.first-1][temp.second]=='o') {stk.push(make_pair(temp.first-1,temp.second));game[temp.first-1][temp.second]='#';}
					}
				}
				if(cnt) cncmpt.pb(cnt);
			}
		}
		// fr(i,0,cncmpt.size()) pf("%d ",cncmpt[i]);
		vector< vector<complex<double> > > poly;
		fr(i,0,cncmpt.size()) {
			vector<complex<double> > vec;
			vec.pb(complex<double>((double)cncmpt[i],0.0));
			vec.pb(complex<double>(1.0,0.0));
			poly.pb(vec);
		}
		
	}
	return 0;
}
