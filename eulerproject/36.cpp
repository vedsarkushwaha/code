#include <cstdio>

using namespace std;

bool palliInt(int i) {
  
}

int main() {
  int i,j,k,cnt=0;
  for(i=1;i<=1000000;i++) {
    if(palliInt(i) && pallibin(i)) cnt++;
  }
  printf("%d\n",cnt);
  return 0;
}
