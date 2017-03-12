#include <cstdio>
#include <cmath>
#include <algorithm>

#define ll long long
#define sz 100000000
using namespace std;

int main() {
  ll i=1;
  vector<ll> factorialList;
  factorialList.push_back(1);
  for(i=1;i<=20;i++) {
    factorialList.push_back(factorialList.top()*i);
  }

  for(i=1;i<=100)
}
