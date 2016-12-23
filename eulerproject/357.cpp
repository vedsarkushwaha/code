#include <cstdio>
#include <set>
#include <cmath>

#define sz 100

using namespace std;

int prm[sz+1];
set<int> noPrime;
set<int> prime;

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
  for(i=1;i<sz;i++) {
    if(prm[i]==0) prime.insert(i);
  }
}

bool isPrime(int num1, int num2) {
  int tmp=num1+num2;
  // if(noPrime.find(num1*num2)!=noPrime.end()) {
  //   return false;
  // }
  if(prime.find(tmp)!=prime.end()) {
    return true;
  }
  return false;
}

int main() {
  int i,j,tmp;
  long long iSum=0,sum=sz;
  seive_fun();
  printf("seive_fun done");
  fflush(stdout);
  for(i=1;i<=10;i++) {
    // printf("%d\n",i);
    for(j=1;j<=10;j++) {
      printf("%d\n",i*j);
      if(!isPrime(i,j)) {
        noPrime.insert(i*j);
      }
    }
  }
  printf("noPrime search done");
  fflush(stdout);
  set<int>::iterator it;
  for(it=noPrime.begin();it!=noPrime.end();++it) {
    printf("%d\n",*it);
    iSum+=(*it);
  }
  sum = (sum*(sum+1))/2 - iSum;
  printf("%lld %lld\n",iSum,sum);
}
