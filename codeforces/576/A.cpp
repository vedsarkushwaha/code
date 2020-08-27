#include <cstdio>
#include <set>
#include <vector>

using namespace std;

set<int> numSet;

bool chkPrime(int n) {
  int i;
  for(i=2;i<n;i++) {
    if((n%i) == 0) return false;
  }
  return true;
}

void init(int n) {
  int i;
  int tmp;

  for(i=2;i<n;i++) {
    if(chkPrime(i)) {
      tmp = i*i;
      while(tmp<=1000) {
        numSet.insert(tmp);
        tmp = tmp * i;
      }
    }
  }
}

bool chkSquare(int n) {
    return numSet.find(n)!=numSet.end();
}

int main() {
  int n;
  scanf("%d",&n);
  int i;
  vector<int> vec;

  init(n);

  for(i=2;i<=n;i++) {
    if(chkPrime(i) || chkSquare(i)) {
      // printf("%d ",i);
      vec.push_back(i);
    }
  }

  printf("%lu\n",vec.size());
  for(i=0;i<vec.size();i++) {
    printf("%d ",vec[i]);
  }
  return 0;
}
