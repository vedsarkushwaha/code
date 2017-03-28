#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <cassert>

using namespace std;
int arr[10000000];

int fun3(int n) {
  return (n*(n+1))/2;
}

int fun4(int n) {
  return n*n;
}

int fun5(int n) {
  return (n*(3*n-1))/2;
}

int fun6(int n) {
  return (n*(2*n-1));
}

int fun7(int n) {
  return (n*(5*n-3))/2;
}

int fun8(int n) {
  return n*(3*n-2);
}

bool chkDig(int num) {
  int cnt=0;
  while(num!=0) {
    cnt++;
    num/=10;
  }
  assert(cnt==4);
  return true;
}
// vector<int> getAll(int i) {
//   vector<int> vec;
//   vec.push_back(fun3(i));
//   vec.push_back(fun4(i));
//   vec.push_back(fun5(i));
//   vec.push_back(fun6(i));
//   vec.push_back(fun7(i));
//   vec.push_back(fun8(i));
//   return vec;
// }

int main() {
  int i=44;
  while(i<140) {
    i++;
    int tmp=fun3(i);
    printf("3 -- %d %d\n",i,tmp);
    if(chkDig(tmp)) {
      int f3=tmp/100;
      int l3=tmp%100;
      int j=31;
      while(j<99) {
        j++;
        int tmp=fun4(j);
        printf("4 -- %d %d\n",j,tmp);
        if(chkDig(tmp)) {
          int f4=tmp/100;
          int l4=tmp%100;
          if(l3==f4) {
            int k=25;
            while(k<81) {
              k++;
              int tmp=fun5(k);
              printf("5 -- %d %d\n",k,tmp);
              if(chkDig(tmp)) {
                int f5=tmp/100;
                int l5=tmp%100;
                if(l4==f5) {
                  int l=22;
                  while(l<70) {
                    l++;
                    int tmp=fun6(l);
                    printf("6 -- %d %d\n",l,tmp);
                    if(chkDig(tmp)) {
                      int f6=tmp/100;
                      int l6=tmp%100;
                      if(l5==f6) {
                        int m=20;
                        while(m<63) {
                          m++;
                          int tmp=fun7(l);
                          printf("7 -- %d %d\n",m,tmp);
                          if(chkDig(tmp)) {
                            int f7=tmp/100;
                            int l7=tmp%100;
                            if(l6==f7) {
                              int n=18;
                              while(n<58) {
                                n++;
                                int tmp=fun8(l);
                                printf("8 -- %d %d\n",n,tmp);
                                if(chkDig(tmp)) {
                                  int f8=tmp/100;
                                  int l8=tmp%100;
                                  if(l7==f8 && l8==f3) {
                                    printf("%d\n",fun3(i));
                                    printf("%d\n",fun4(j));
                                    printf("%d\n",fun5(k));
                                    printf("%d\n",fun6(l));
                                    printf("%d\n",fun7(m));
                                    printf("%d\n",fun8(n));
                                    return 0;
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return 0;
}
