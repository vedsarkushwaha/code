#include<cstdio>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

int main() {
  long long n,d,m;
  long long i,tmp,x;
  long long big;

  long long ans=0,res=0;

  vector<long long> vec;
  vector<long long> prefixSum;
  scanf("%lld %lld %lld",&n,&d,&m);
  for(i=0;i<n;i++) {
    scanf("%lld",&tmp);
    vec.push_back(tmp);
    prefixSum.push_back(tmp);
  }

  sort(vec.begin(),vec.end());
  sort(prefixSum.begin(),prefixSum.end());

  for(i=1;i<prefixSum.size();i++) {
    prefixSum[vec.size()-i-1] += prefixSum[vec.size()-i];
    // printf("%lld ",vec[i]);
  }
  // printf("\n");

  big = vec.size()-1;
  for(i=0;i<vec.size();i++) {
    if(vec[i]>m) {
      big=i;
      break;
    }
  }

  // printf("Big=%lld\n",big);

  x=0;
  tmp = n-1-x-x*d;
  while(tmp >= 0) {
    ans = vec[vec.size()-1];

    // printf("ans=%lld tmp=%lld x=%lld\n",ans,tmp,x);

    // for(i=0;i<x && (vec.size()-2-i) >= big;i++) {
    //   ans += vec[vec.size()-2-i];
    // }

    ans += prefixSum[prefixSum.size()-2-x];

    // for(i=0;i<tmp && ((big-1-i)>=0);i++) {
    //   ans += vec[big-1-i];
    // }

    ans += prefixSum[tmp] - prefixSum[big];

    res = max(ans, res);

    // printf("res=%lld ans=%lld\n",res,ans);

    x++;
    tmp = n-1-x-x*d;
  }
  printf("%lld",res);
  return 0;
}
