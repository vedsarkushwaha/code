#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> data;
vector<int> inp;

int find(int val, int start, int end) {
  int i;
  for(i=start;i<end;i++) {
    if(data[i]==val) return i;
  }
  return end;
}

void getInput() {
  int i,tmp;
  for(i=0;i<50;i++) {
    scanf("%d",&tmp);
    inp.push_back(tmp);
    while(tmp!=0) {
      data.push_back(tmp%10);
      tmp=tmp/10;
    }
  }
}

bool chk() {
  int i,tmp,flag;
  for(i=0;i<50;i++) {
    flag=0;
    int num = inp[i];
    tmp = find(0,150,num%10);
    if(tmp!=150) {
      num/=10;
      tmp = find(tmp+1,150,num%10);
      if(tmp!=150) {
        num/=10;
        tmp = find(tmp+1,150,num%10);
        if(tmp!=150) flag=1;
      }
    }
    if(!flag) return false;
  }
  return true;
}

vector<int> getMin() {
  vector<int> minVec;
  int i;
  minVec.push_back(data[0]);
  for(i=1;i<150;i++) {
    if(minVec.back()==data[i]) continue;
    minVec.push_back(data[i]);
  }
  return minVec;
}

void print(vector<int> vec) {
  int i;
  for(i=0;i<vec.size();i++) printf("%d ",vec[i]);
}

int main() {
  int gMin=INT_MAX;
  getInput();
  do {
    if(chk()) {
      vector<int> tmp = getMin();
      if(tmp.size()<gMin) {
        print(tmp);
        gMin=tmp.size();
      }
    }
  } while(next_permutation(data.begin(),data.end()));
  return 0;
}
