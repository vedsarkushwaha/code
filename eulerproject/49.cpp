#include <cstdio>
#include <set>
#include <cmath>
#include <vector>
#define sz 10000000

using namespace std;

int prm[sz+1];
vector<int> primeSet;
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

bool chkPermut(int a,int b,int c) {
  int aArr[10]={0};
  int bArr[10]={0};
  int cArr[10]={0};
  while(a!=0) {
    aArr[a%10]+=1;
    a=a/10;
  }
  while(b!=0) {
    bArr[b%10]+=1;
    b=b/10;
  }
  while(c!=0) {
    cArr[c%10]+=1;
    c=c/10;
  }
  for(int i=0;i<10;i++) {
    if(aArr[i]!=bArr[i] || bArr[i]!=cArr[i]) return false;
  }
  return true;
}

int main() {
  seive_fun();
  int i,j,k;
  for(i=1000;i<10000;i++) {
    if(prm[i]==0) primeSet.push_back(i);
  }
  int tmp1,tmp2,tmp3;
  vector<int> vec;
  for(i=0;i<primeSet.size();++i) {
    for(j=i+1;j<primeSet.size();++j) {
      for(k=j+1;k<primeSet.size();++k) {
        tmp1=primeSet[i];
        tmp2=primeSet[j];
        tmp3=primeSet[k];
        if((tmp3-tmp2 == tmp2-tmp1) && chkPermut(tmp1,tmp2,tmp3)) {
          printf("%d %d %d\n",tmp1,tmp2,tmp3);
        }
      }
    }
  }
  return 0;
}
