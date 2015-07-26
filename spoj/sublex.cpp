#include<bits/stdc++.h>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1=0,tmp2=0,tmp3=0,tmp=0,tmp4=0,tmp5=0,flag=0,T=0,Q=0
#define pb push_back
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
#define N 90010
using namespace std;

int rank[N], pos[N];
string str;

bool smaller_first_char(int a, int b) {
  return str[a] < str[b];
}
 
void suffixSort() {
  int cnt[N], next[N];
  bool bh[N], b2h[N];
  int n=str.length();
  for (int i=0; i<n; ++i) {
    pos[i] = i;
  }
  sort(pos, pos + n, smaller_first_char);
  for(int i=0; i<n; ++i) {
    bh[i] = i == 0 || str[pos[i]] != str[pos[i-1]];
    b2h[i] = false;
  }
  for (int h = 1; h < n; h <<= 1){
    int buckets = 0;
    for (int i=0, j; i < n; i = j){
      j = i + 1;
      while (j < n && !bh[j]) j++;
      next[i] = j;
      buckets++;
    }
    if (buckets == n) break;
    for (int i = 0; i < n; i = next[i]){
      cnt[i] = 0;
      for (int j = i; j < next[i]; ++j){
        rank[pos[j]] = i;
      }
    }
 
    cnt[rank[n - h]]++;
    b2h[rank[n - h]] = true;
    for (int i = 0; i < n; i = next[i]){
      for (int j = i; j < next[i]; ++j){
        int s = pos[j] - h;
        if (s >= 0) {
          int head = rank[s];
          rank[s] = head + cnt[head]++;
          b2h[rank[s]] = true;
        }
      }
      for (int j = i; j < next[i]; ++j){
        int s = pos[j] - h;
        if (s >= 0 && b2h[rank[s]]){
          for (int k = rank[s]+1; !bh[k] && b2h[k]; k++) b2h[k] = false;
        }
      }
    }
    for (int i=0; i<n; ++i){
      pos[rank[i]] = i;
      bh[i] |= b2h[i];
    }
  }
  for (int i=0; i<n; ++i){
    rank[pos[i]] = i;
  }
}

int main() {
  var(int);
  cin>>str;
  suffixSort();
  vi rankArr;
  fr(i,0,str.length()) {
    if(i==0) rankArr.pb(str.length()-pos[i]);
    else rankArr.pb(rankArr[i-1]+str.length()-pos[i]);
  }
  // fr(i,0,rankArr.size()) {
  //   pf("%d ",rankArr[i]);
  // }
  sc("%d",&Q);
  while(Q--) {
    sc("%d",&i);
    tmp=lower_bound(rankArr.begin(),rankArr.end(),i)-rankArr.begin();
    if(tmp) j=(i-rankArr[tmp-1]);
    else j=i;
    i=tmp;
    fr(k,pos[i],pos[i]+j) pf("%c",str[k]);
    pf("\n");
  }
  return 0;
}