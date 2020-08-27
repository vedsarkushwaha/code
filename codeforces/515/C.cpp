#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

long long fact(long long num) {
  long long i, ans;
  ans = 1;
  for(i=1;i<=num;i++) {
    ans *= i;
  }
  return ans;
}

long long digitFact(long long num) {
  long long ans=1;
  long long tmp;
  while(num!=0) {
    // printf("%lld\n",num);
    tmp = num%10;
    ans *= fact(tmp);
    num = num/10;
  }
  return ans;
}

int main() {
  long long n,num,tmp,tmp1,i;
  scanf("%lld",&n);
  scanf("%lld",&num);

  long long arr[10];
  arr[0]=0;
  arr[1]=1;
  arr[2]=2;
  arr[3]=3;
  arr[4]=322;
  arr[5]=5;
  arr[6]=53;
  arr[7]=7;
  arr[8]=7222;
  arr[9]=7332;

  vector<long long> vec;
  while(num!=0) {
    tmp = num%10;
    num=num/10;
    if(arr[tmp]>9) {
      tmp1 = arr[tmp];
      while(tmp1!=0) {
        vec.push_back(tmp1%10);
        tmp1=tmp1/10;
      }
    }
    else {
      vec.push_back(arr[tmp]);
    }
  }
  sort(vec.begin(),vec.end(), greater<long long>());

  for(i=0;i<vec.size();i++) {
    if(vec[i]<=1) break;
    printf("%lld",vec[i]);
  }
  // printf("%lld",digitFact(num));
  return 0;
}
