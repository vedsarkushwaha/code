#include <cstdio>
#include <vector>
#include <set>
#include <cmath>
#include <map>
#define sz 1000000

using namespace std;

int prm[sz+1];
set<int> primeSet;
vector<int> primeVec;

void seive_fun() {
	int i,j,k,limit;
	prm[0]=1;
	prm[1]=1;
	limit=sqrt(sz);
	for(i=2;i<=limit;i++) {
		if(prm[i]==0) {
			k=sz/i;
			for(j=2;j<=k;j++) prm[i*j]=1;
		}
	}
}

int concat(int a,int b) {
  int tmp1=1;
  int tmp2=b;
  while(tmp2!=0) {
    tmp1*=10;
    tmp2/=10;
  }
  return a*tmp1+b;
}

bool chkPrime(int num) {
  if(num<sz) {
    if(primeSet.find(num)!=primeSet.end()) return true;
    else return false;
  }
  int limit=sqrt(num);
  int i=0;
  while(primeVec[i]<=limit) {
    if(num%primeVec[i]==0) return false;
    i++;
  }

  return true;
}

bool chkPair(int x, int y) {
  if(chkPrime(concat(x,y))) return true;
  return false;
}

bool chk4(int i,int j,int k,int l) {
  vector<int> vec;
  int x,y;
  vec.push_back(i);
  vec.push_back(j);
  vec.push_back(k);
  vec.push_back(l);
  // printf("%d %d %d %d:\n",i,j,k,l);
  for(x=0;x<4;x++) {
    for(y=x+1;y<4;y++) {
      if(!chkPair(vec[x],vec[y]) || !chkPair(vec[y],vec[x])) return false;
    }
  }
  // printf("true\n");
  return true;
}

int main() {
  int i,j,k,l,m;
  seive_fun();
  for(i=0;i<=sz;i++) {
    if(prm[i]==0) {
      primeSet.insert(i);
      primeVec.push_back(i);
    }
  }

  map<int,vector<int> > primeSet;
  map<int,vector<int> >::iterator it;
  int tmpi,tmpj;
  for(i=0;i<primeVec.size();i++) {
    tmpi=primeVec[i];
    if(tmpi>10000) break;
    for(j=i+1;j<primeVec.size();j++) {
      tmpj=primeVec[j];
      if(tmpj>10000) break;
      if(chkPair(tmpi,tmpj) && chkPair(tmpj,tmpi)) {

        if(primeSet.find(tmpi)==primeSet.end()) {
          // first entry
          vector<int> vec;
          // vec.push_back(tmpi);
          vec.push_back(tmpj);
          primeSet.insert(make_pair(tmpi,vec));
        }
        else {
          it = primeSet.find(tmpi);
          (it->second).push_back(tmpj);
        }
        if(primeSet.find(tmpj)==primeSet.end()) {
          // first entry
          vector<int> vec;
          vec.push_back(tmpi);
          // vec.push_back(tmpj);
          primeSet.insert(make_pair(tmpj,vec));
        }
        else {
          it = primeSet.find(tmpj);
          (it->second).push_back(tmpi);
        }
      }
    }
  }

  // print map
  int smTmp,gsmTmp=10000000;
  for(it=primeSet.begin();it!=primeSet.end();it++) {
    printf("i=%d\n",it->first);
    // for(j=0;j<(it->second).size();j++) {
    //   printf("%d ",(it->second)[j]);
    // }
    // printf("\n=================================\n");
    printf("size=%d\n",(it->second).size());
    for(i=0;i<(it->second).size();i++) {
      for(j=i+1;j<(it->second).size();j++) {
        for(k=j+1;k<(it->second).size();k++) {
          for(l=k+1;l<(it->second).size();l++) {
            if(chk4((it->second)[i],(it->second)[j],(it->second)[k],(it->second)[l])) {
              smTmp=(it->first)+(it->second)[i]+(it->second)[j]+(it->second)[k]+(it->second)[l];
              printf("%d %d %d %d %d\n",(it->first),(it->second)[i],(it->second)[j],(it->second)[k],(it->second)[l]);
              gsmTmp=min(gsmTmp,smTmp);
              printf("%d\n",gsmTmp);
            }
          }
        }
      }
    }
  }
  printf("%d",gsmTmp);
  return 0;
}
