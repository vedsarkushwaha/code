#include<cstdlib>
#include<vector>
#include<complex>
#include<cassert>
#include<algorithm>

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
#define md 1000000007
using namespace std;

long double fmd=1000000007;

void printVec(vector<complex<long double> > &vec) {
  var(int);
  ifr(i,vec.size()-3,-1) {
    assert(round(vec[i].real())<=fmd);
    pf("%.0Lf ",abs(vec[i]));
  }
}

vector<complex<long double> > fft(const vector<complex<long double> > &as) {
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

  vector<complex<long double> > roots(n);
  for (int i = 0; i < n; i++) {
    long double alpha = 2 * M_PI * i / n;
    roots[i] = complex<long double>(cos(alpha), sin(alpha));
  }

  vector<complex<long double> > cur(n);
  for (int i = 0; i < n; i++)
    cur[i] = as[rev[i]];

  for (int len = 1; len < n; len <<= 1) {
    vector<complex<long double> > ncur(n);
    int rstep = roots.size() / (len * 2);
    for (int pdest = 0; pdest < n;) {
      int p1 = pdest;
      for (int i = 0; i < len; i++) {
        complex<long double> val = roots[i * rstep] * cur[p1 + len];
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

vector<complex<long double> > fft_rev(const vector<complex<long double> > &as) {
  vector<complex<long double> > res = fft(as);
  for (int i = 0; i < (int)res.size(); i++) res[i] /= as.size();
  reverse(res.begin() + 1, res.end());
  return res;
}

vector<complex<long double> > prodPoly(vector<complex<long double> > &pol1,vector<complex<long double> > &pol2) {
  // index 0 should contain lowest degree coeff
  int n1,n2,deg,ans_deg;
  var(int);
  vector<complex<long double> > dft1,dft2,ans;
  n1=pol1.size();
  n2=pol2.size();
  ans_deg=n1+n2-1;
  deg=max(n1,n2);
  deg=pow(2,ceil(log2(deg)));
  fr(i,n1,2*deg) {
    pol1.pb(complex<long double>(0.0,0.0));
  }
  fr(i,n2,2*deg) {
    pol2.pb(complex<long double>(0.0,0.0));
  }

  dft1=fft(pol1);
  dft2=fft(pol2);

  fr(i,0,dft1.size()) {
    ans.pb(dft1[i]*dft2[i]);
  }
  ans=fft_rev(ans);

  ans.erase(ans.begin()+ans_deg,ans.end());
  fr(i,0,ans.size()) {
    ans[i].real()=abs(round(fmod(ans[i].real(),fmd)));
    ans[i].imag()=0.0;
  }
  return ans;
}

long double nArr[1001],mArr[1001],arr[1001];
vector<vector<complex<long double> > > vec;
int main() {
    var(int);
    int N,M,C;
    sc("%d %d %d",&N,&M,&C);
    fr(i,0,N) {
        sc("%d",&tmp);
        nArr[tmp]++;
    }
    fr(i,0,M) {
        sc("%d",&tmp);
        mArr[tmp]++;
    }
    fr(i,0,C+1) arr[i]=fmod(nArr[i]*mArr[i],fmd);
    fr(i,0,C+1) {
        vector<complex<long double> > p1;
        p1.pb(complex<long double>(arr[i],0.0));
        p1.pb(complex<long double>(1.0,0.0));
        vec.pb(p1);
    }
    vector<complex<long double> > ans;   
    while(vec.size()!=1) {
        i=0;
        while(i<vec.size()-1) {
            ans=prodPoly(vec[i],vec[i+1]);
            vec[i/2]=ans;
            i+=2;
        }
        if(vec.size()-1==i) {
            vec[i/2]=vec[i];
            vec.resize(i/2+1);
        }
        else vec.resize(i/2);
    }
    printVec(vec[0]);
    return 0;
}