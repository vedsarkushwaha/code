#include <bits/stdc++.h>
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
double md=100003;

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
// int flag;
vector<complex<double> > fft_rev(const vector<complex<double> > &as) {
  vector<complex<double> > res = fft(as);
  for (int i = 0; i < (int)res.size(); i++) {
  	res[i] /= as.size();
  	double temp;
  	temp=abs(floor(round(res[i].real())/md));
  	// pf("%lf %lf %lf ",res[i].real(),temp*md,res[i].real()-temp*md);
  	// if(round(res[i].real()-temp*md)==100003) {
  	// 	pf("%lf %lf %lf:\n",res[i].real(),temp,temp*md);
  	// 	// flag=1;
  	// }
  	res[i]=complex<double>(round(res[i].real()-temp*md),round(res[i].imag()));
  	// pf("%lf %lf\n",res[i].real(),res[i].imag());

  }
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

  fr(i,0,dft1.size()) {
    ans.pb(dft1[i]*dft2[i]);
  }
  ans=fft_rev(ans);
  ans.erase(ans.begin()+ans_deg,ans.end());
  return ans;
}

int main() {
  var(int);
  int n1,n2,deg;
  vector< vector<complex<double> > > inp[20];
  
  sc("%d",&N);
  fr(i,0,N) {
    vector<complex<double> > temp;
    sc("%d",&tmp);
    temp.pb(complex<double>((double)tmp,0.0));
    temp.pb(complex<double>(1.0,0.0));
    inp[0].pb(temp);
  }
  j=-1;
  while(1) {
    j++;
    i=0;
    while(i<inp[j].size()) {
      if(i==inp[j].size()-1) inp[j+1].pb(inp[j][i]);
      else inp[j+1].pb(prodPoly(inp[j][i],inp[j][i+1]));
      i+=2;
    }
    if(inp[j].size()==1) break;
  }
  sc("%d",&Q);
  while(Q--) {
  	sc("%d",&tmp);
  	pf("%.0lf\n",abs(inp[j][0][N-tmp].real()));
  }
  return 0;
}