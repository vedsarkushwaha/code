#include <cstdio>
#include <set>
#include <cmath>

#define sz 100000000

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

bool isPrime(int tmp) {
  if(prime.find(tmp)!=prime.end()) {
    return true;
  }
  return false;
}

int main() {
  int i,j,tmp;
  long long iSum=0,sum=0;
  seive_fun();
  printf("seive_fun done\n");
  fflush(stdout);
  int flag;
  for(i=1;i<=sz;i++) {
    // printf("%d\n",i);
    flag=0;
    for(j=1;j<=sqrt(i)+1;j++) {
      // printf("%d\n",i*j);
      if(i%j==0) {
        if(!isPrime(j+i/j)) {
          flag=1;
          break;
        }
      }
    }
    if(!flag) {
      printf("%d\n",i);
      sum+=i;
    }
  }
  printf("%lld\n",sum);

  // printf("noPrime search done");
  // fflush(stdout);
  // set<int>::iterator it;
  // for(it=noPrime.begin();it!=noPrime.end();++it) {
  //   printf("%d\n",*it);
  //   iSum+=(*it);
  // }
  // sum = (sum*(sum+1))/2 - iSum;
  // printf("%lld %lld\n",iSum,sum);
}
