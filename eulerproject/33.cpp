#include <cstdio>
#include <set>
#include <cmath>
#include <iostream>
#include <vector>
#include <set>
#include <cassert>

using namespace std;

int main() {
  double i,j,k,d,n;
  double tmp1,tmp2,tmp3,err;
  err = 1.0/1000.0;
  printf("%lf\n",err);
  // for(i=1;i<10;i++) {
  //   for(n=1;n<10;n++) {
  //     for(d=n+1;d<10;d++) {
  //       tmp1 = 10*i + n;
  //       tmp2 = 10*d + i;
  //       if(abs(tmp1/tmp2 - n/d)<err) {
  //         printf("%lf %lf\n", 10*i+n, 10*d+i);
  //       }
  //     }
  //   }
  // }

  for(i=1;i<10;i++) {
    for(n=1;n<10;n++) {
      for(d=n+1;d<10;d++) {
        tmp1 = 10*n + i;
        tmp2 = 10*i + d;
        if(abs(tmp1/tmp2 - n/d)<err) {
          printf("%lf %lf\n", 10*n+i, 10*i+d);
        }
      }
    }
  }
  return 0;
}
