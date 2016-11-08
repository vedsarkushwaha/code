#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

bool chkPrime(int num) {
  int limit = sqrt(num)+1;
  printf("%d\n",num);
  int i;
  for(i=2;i<=limit;i++) {
    if(num%i==0) {
      printf("%d %d\n",num,i);
      return false;
    }
  }
  printf("reached");
  return true;
}

int main() {
  int num[7]={1,2,3,4,5,6,7};
  int psNum,ans=0;
  int i;
  do {
    psNum=0;
    for(i=0;i<7;i++) {
      psNum=psNum*10+num[i];
    }
    if(chkPrime(psNum)) {
      ans=max(ans, psNum);
    }
  } while(next_permutation(num,num+7));
  printf("%d\n",ans);
  return 0;
}
