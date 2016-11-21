#include <cstdio>
#include <set>
#include <vector>
#include <map>
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

vector<int> getAll(int i) {
  vector<int> vec;
  vec.push_back(fun3(i));
  vec.push_back(fun4(i));
  vec.push_back(fun5(i));
  vec.push_back(fun6(i));
  vec.push_back(fun7(i));
  vec.push_back(fun8(i));
  return vec;
}

int main() {
  int i,j,k;
  vector<pair<int,int> > vec[100];
  for(i=10;i<1000;i++) {
    vector<int> vec = getAll(i);
    for(j=0;j<vec.size();j++) {
      vec[vec[j]/100].push_back(make_pair(vec[j]%100),j+3);
    }
  }
  return 0;
}
