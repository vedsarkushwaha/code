#include <cstdio>
#include <set>
#include <cmath>
#define sz 10000000

using namespace std;

int prm[sz+1];
set<int> primeSet;
int arr[sz+1];

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

int getPFcnt(int i) {
  set<int>::iterator it;
  int cnt=0,tmp;
  for(it=primeSet.begin();it!=primeSet.end();++it) {
    tmp = *it;
    // printf("prime=%d",tmp);
    // fflush(stdout);
    if(tmp>sqrt(i)) break;
    if(i%tmp==0) {
      cnt++;
      while(i%tmp==0) {
        i=i/tmp;
      }
    }
  }
  if(i!=1) cnt++;
  return cnt;
}

int main() {
  seive_fun();
  for(int i=0;i<=sz;i++) {
    if(prm[i]==0) primeSet.insert(i);
  }

  int i;

  i=97;
  arr[i]=getPFcnt(i);
  // printf("%d %d\n",i,arr[i]);
  // fflush(stdout);

  i++;
  arr[i]=getPFcnt(i);
  // printf("%d %d\n",i,arr[i]);
  // fflush(stdout);

  i++;
  arr[i]=getPFcnt(i);
  // printf("%d %d\n",i,arr[i]);
  // fflush(stdout);

  i++;
  while(1) {
    if(i>sz) break;
    arr[i]=getPFcnt(i);
    if(arr[i-3]==arr[i-2] && arr[i-2]==arr[i-1] && arr[i-1]==arr[i] && arr[i]==4) {
      printf("%d\n",i-3);
    }
    // printf("%d %d\n",i,arr[i]);
    // fflush(stdout);
    i++;
  }
  return 0;
}
