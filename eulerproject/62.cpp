#include <cstdio>
#include <vector>
#include <algorithm>

#define ll long long
using namespace std;

void print(vector<ll> vec) {
  int i;
  for(i=0;i<vec.size();i++) {
    printf("%lld ",vec[i]);
  }
}

bool comp(vector<ll> vec1, vector<ll> vec2) {
  for(int i=0;i<10;i++) {
    if(vec1[i]!=vec2[i]) return false;
  }
  return true;
}

int main() {
  ll i,j,k;
  ll tmp1,tmp2,tmp3;
  i=2;
  vector< pair<vector<ll>, ll > > data;
  while(i<=10000) {
    tmp1 = i*i*i;
    vector<ll> vec(10,0);
    pair<vector<ll>, ll > pr;
    pr.second = tmp1;
    while(tmp1!=0) {
      vec[tmp1%10]++;
      tmp1=tmp1/10;
    }
    pr.first = vec;
    data.push_back(pr);
    i++;
  }
  sort(data.begin(),data.end());
  for(i=0;i<data.size();i++) {
    printf("%lld: ",data[i].second);
    print(data[i].first);
    printf("\n");
  }
  printf("size=%d\n",data.size());
  for(i=0;i<data.size();i++) {
    int cnt=1;
    vector<ll> vec = data[i].first;
    for(j=0;j<data.size();j++) {
      if(i==j) continue;
      if(comp(data[i].first, data[j].first)) cnt++;
    }
    if(cnt==5)
      printf("%lld\n",data[i].second);
    // printf("%d\n",cnt);
  }
  return 0;
}
