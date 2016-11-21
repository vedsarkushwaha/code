#include <cstdio>

using namespace std;

int fact(int i) {
  if(i==0 || i==1) return 1;
  else return i*fact(i-1);
}

int digiFact(int i) {
  int tmp;
  int digiFactSum=0;
  while(i!=0) {
    tmp=i%10;
    i=i/10;
    digiFactSum += fact(tmp);
  }
  return digiFactSum;
}

int main() {
  int i,sum=0;
  for(i=3;i<=10000000;i++) {
    if(i==digiFact(i)) {
      printf("%d\n",i);
      sum+=i;
    }
  }
  printf("%d\n", sum);
  return 0;
}
