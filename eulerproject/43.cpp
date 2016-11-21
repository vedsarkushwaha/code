#include <cstdio>
#include <algorithm>
#include <vector>

#define ll long long
#define pf printf

using namespace std;

ll getNum(vector<ll> vec) {
  ll num = 0;
  int i;
  for(i=0;i<vec.size();i++) {
    num=num*10+vec[i];
  }
  return num;
}

bool chk(vector<ll> vec) {
  // check div
  ll num = getNum(vec);
  int tmp,i;
  int arr[7]={2,3,5,7,11,13,17};
  reverse(arr,arr+7);
  for(i=0;i<7;i++) {
    tmp = num%1000;
    if(tmp%arr[i]!=0) return false;
    num=num/10;
  }
  return true;
}

void print(vector<ll> vec) {
  int i;
  for(i=0;i<vec.size();i++) pf("%lld ",vec[i]);
}

int main() {
  ll i,j,k,ans=0;
  vector<ll> vec;
  for(i=0;i<10;i++) vec.push_back(i);
  do {
    if(chk(vec)) {
      print(vec);
      ans+=getNum(vec);
      pf("\n");
    }
  } while(next_permutation(vec.begin(),vec.end()));
  pf("%lld\n",ans);
  return 0;
}
