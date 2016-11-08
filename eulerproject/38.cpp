#include <cstdio>
#include <vector>
#include <set>
using namespace std;

bool chk(vector<int> vec) {
  int tmp,tmp1;
  int arr[10]={0};
  for(int i=0;i<=vec.size();i++) {
    tmp = vec[i];
    while(tmp!=0) {
      if(arr[tmp%10]) return 0;
      else arr[tmp%10]=1;
      tmp=tmp/10;
    }
  }
  int i;
  if(arr[0]==1) return 0;
  for(i=1;i<10;i++) if(arr[i]==0) return 0;
  return 1;
}

int getNum(vector<int> vec) {
  int num=vec[0];
  int times=1,i;
  for(i=1;i<vec.size();i++) {
    times = 1;
    while(times<vec[i]) {
      times*=10;
    }
    num*=times;
    num+=vec[i];
  }
  return num;
}

int main() {
  int n,num,i,j,k;
  vector<int> vec;
  set<int> st;
  for(i=1;i<=100000;i++) {
    for(j=2;j<=9;j++) {
      vec.clear();
      for(k=1;k<=j;k++) {
        vec.push_back(i*k);
      }
      if(chk(vec)) {
        num = getNum(vec);
        st.insert(num);
        printf("%d %d %d\n",i,j,num);
      }
    }
  }
  printf("%d\n",*max_element(st.begin(),st.end()));
  // get max number from st
  return 0;
}
