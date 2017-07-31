#include <cstdio>
#include <cmath>

#define sz 100000000
using namespace std;

int prm[sz+1];

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

int getNextPrime(int prime) {
  prime++;
  while(prm[prime]==1) {
    prime++;
  }
  return prime;
}

int chgDig(int num, int index,int newDig) {
  // printf("%d %d %d\n",num,index,newDig);
  int tmp1 = num/(pow(10,index));
  int tmp2 = num%((int)pow(10,index-1));
  int tmp3 = tmp1*10+newDig;
  int tmp4 = tmp3*(pow(10,index-1));
  int tmp5 = tmp4+tmp2;
  // printf("%d %d %d\n",num,index,newDig);
  // printf("%d %d %d %d %d\n",tmp1,tmp2,tmp3,tmp4,tmp5);
  // fflush(stdout);
  return tmp5;
}

int main() {
  int i,j,k;
  seive_fun();
  int numDig=6;
  while(1) {
    int range=pow(10,numDig);
    int prime=getNextPrime(range/10);    
    printf("prime=%d\n",prime);
    for(i=1;i<range;i++) { // combination loop
      int cnt=0;
      for(j=1;j<10;j++) { // digit loop
        int tmp = prime;
        for(k=0;k<numDig;k++) { // for the combi, override digits
          if(i&(1<<k)) {
            tmp = chgDig(tmp,k+1,j);
          }
        }
        if(prm[tmp]==0) {
          printf("Found: %d\n",tmp);
          cnt++;
        }
      }
      if(cnt>=8) {
        printf("%d",prime);
        return 0;
      }
    }
    numDig++;
  }
  return 0;
}
