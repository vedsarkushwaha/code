#include <cstdio>
#define ll long long
using namespace std;

bool chk(ll x) {
  ll tmp1=x,tmp2=2*x,tmp3=3*x,tmp4=4*x,tmp5=5*x,tmp6=6*x;
  int i;
  int arr1[10]={0};
  int arr2[10]={0};
  int arr3[10]={0};
  int arr4[10]={0};
  int arr5[10]={0};
  int arr6[10]={0};

  while(tmp1!=0) {
    arr1[tmp1%10]+=1;
    tmp1=tmp1/10;
  }

  while(tmp2!=0) {
    arr2[tmp2%10]+=1;
    tmp2=tmp2/10;
  }

  while(tmp3!=0) {
    arr3[tmp3%10]+=1;
    tmp3=tmp3/10;
  }

  while(tmp4!=0) {
    arr4[tmp4%10]+=1;
    tmp4=tmp4/10;
  }

  while(tmp5!=0) {
    arr5[tmp5%10]+=1;
    tmp5=tmp5/10;
  }

  while(tmp6!=0) {
    arr6[tmp6%10]+=1;
    tmp6=tmp6/10;
  }

  for(i=0;i<10;i++) {
    if(arr1[i]!=arr2[i] || arr2[i]!=arr3[i] || arr3[i]!=arr4[i] || arr4[i]!=arr5[i] || arr5[i]!=arr6[i]) {
      return false;
    }
  }
  return true;
}

int main() {
  ll x=1;
  for(x=1;x<17;x++) {
    if(chk(x)) printf("%lld\n",x);
  }
  printf("Done\n");
  fflush(stdout);
  for(x=100;x<170;x++) {
    if(chk(x)) printf("%lld\n",x);
  }
  printf("Done\n");
  fflush(stdout);
  for(x=1000;x<1700;x++) {
    if(chk(x)) printf("%lld\n",x);
  }
  printf("Done\n");
  fflush(stdout);
  for(x=10000;x<17000;x++) {
    if(chk(x)) printf("%lld\n",x);
  }
  printf("Done\n");
  fflush(stdout);
  for(x=100000;x<170000;x++) {
    if(chk(x)) printf("%lld\n",x);
  }
  printf("Done\n");
  fflush(stdout);
  for(x=1000000;x<1700000;x++) {
    if(chk(x)) printf("%lld\n",x);
  }
  printf("Done\n");
  fflush(stdout);
  for(x=10000000;x<17000000;x++) {
    if(chk(x)) printf("%lld\n",x);
  }
  printf("Done\n");
  fflush(stdout);
  return 0;
}
