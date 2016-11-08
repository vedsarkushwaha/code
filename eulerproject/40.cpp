#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int main() {
  string num;
  int i;
  for(i=1;i<1000000;i++) {
    num+=to_string(i);
  }
  // cout<<num<<endl;
  printf("%d\n", (num[0]-'0') * (num[9]-'0') * (num[99]-'0') * (num[999]-'0')
  * (num[9999]-'0') * (num[99999]-'0') * (num[999999]-'0'));

  return 0;
}
