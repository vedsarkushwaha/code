#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#define l 12000
using namespace std;

set<double> ans;

int main() {
  double one = 1.0;
  double two = 2.0;
  double three = 3.0;
  double onetwo = one/two;
  double onethree = one/three;
  double temp;
  vector<double> vec;
  double i,j,cnt=0;
  for(i=1;i<=l;i++) {
    for(j=1;j<i;j++) {
      temp = j/i;
      if(temp>onethree && temp<onetwo) {
        // printf("%.lf %.lf\n",j,i);
        // cnt++;
        ans.insert(temp);
      }
    }
  }
  printf("%lu\n",ans.size());
  return 0;
}
