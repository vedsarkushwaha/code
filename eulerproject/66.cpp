#include <cstdio>
#include <map>
#include <cmath>

#define ll long long

using namespace std;

map<ll,ll> mp;

void init() {
  ll i;
  i=3000000000;
  // printf("%lld %lld\n",i,i*i);
  for(i=1;i<=3000000000;i++) {
    mp.insert(make_pair(i*i,i));
  }
}

int main() {
  ll D,x,y;
  ll i,j,k;
  ll flag;
  map<ll,ll>::iterator it;
  init();
  for(D=2;D<=1000;D++) {
    flag=0;
    if(mp.find(D)!=mp.end()) continue;
    for(it=mp.begin();it!=mp.end();++it) {
      if(((it->first)-1)%D == 0) {
        k=((it->first)-1)/D;
        if(mp.find(k)!=mp.end()) {
          // printf("%lld %lld %lld\n",it->second,D,mp.find(k)->second);
          flag=1;
          break;
        }
      }
    }

    if(!flag) {
      printf("Not found for D=%lld\n",D);
    }
  }
  return 0;
}
