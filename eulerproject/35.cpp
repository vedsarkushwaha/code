#include <cstdio>
#include <cmath>
#include <set>
#include <vector>

#define sz 1000000

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

int getLength(int num) {
  int cnt=0;
  while(num!=0) {
    num=num/10;
    cnt++;
  }
  return cnt;
}

vector<int> getRotations(int num) {
  vector<int> rotations;
  int len=getLength(num);
  int tmp1,tmp2;
  for(int i=0;i<len;i++) {
    rotations.push_back(num);
    tmp1 = num%10;
    num=num/10;
    tmp1*=(pow(10,len-1));
    num+=tmp1;
    rotations.push_back(num);
  }
  return rotations;
}

int main() {
	seive_fun();
  set<int> primeSet;
  for(int i=0;i<=sz;i++) {
    if(prm[i]==0) primeSet.insert(i);
  }

  vector<int> primeRotation;
  set<int>::iterator it;
  int cnt=0,flag;
  for(it=primeSet.begin();it!=primeSet.end();it++) {
    primeRotation = getRotations(*it);
    flag=0;
    for(int i=0;i<primeRotation.size();i++) {
      if(primeSet.find(primeRotation[i])==primeSet.end()) {
        flag=1;
        break;
      }
    }
    if(flag==0) {
      printf("%d\n",*it);
      cnt++;
      // primeSet.erase(it);
    }
  }
  printf("%d\n",cnt);
  return 0;
}
