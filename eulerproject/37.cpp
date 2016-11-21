#include <cstdio>
#include <cmath>
#include <set>
#include <vector>
#include <string>
#include <cstring>

#define sz 10000000
using namespace std;

int prm[sz+1];
set<int> primeSet;

void seive_fun() {
	int i,j,k,limit;
	prm[0]=1;
	prm[1]=1;
	limit=sqrt(sz);
	for(i=2;i<=limit;i++) {
		if(prm[i]==0) {
			k=sz/i;
			for(j=2;j<=k;j++)
				prm[i*j]=1;
		}
	}
}

bool rTrunch(int num) {
  int tmp=num;
  while(tmp!=0) {
    if(primeSet.find(tmp)==primeSet.end()) return false;
    tmp=tmp/10;
  }
  return true;
}

bool lTrunch(int num) {
  int tmp=num;
  while(tmp>9) {
    if(primeSet.find(tmp)==primeSet.end()) return false;
    tmp = stoi(to_string(tmp).substr(1));
  }
  if(primeSet.find(tmp)==primeSet.end()) return false;
  return true;
}

int main() {
  int i;
  seive_fun();
  for(i=0;i<=sz;i++) {
    if(prm[i]==0) primeSet.insert(i);
  }

  set<int>::iterator it;
  for(it=primeSet.begin();it!=primeSet.end();it++) {
    if(lTrunch(*it) && rTrunch(*it)) {
      printf("%d\n", *it);
    }
  }
  return 0;
}
