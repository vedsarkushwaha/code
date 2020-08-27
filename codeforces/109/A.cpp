#include <cstdio>
#include <vector>

using namespace std;

vector<int> vec;
int flag;
void printVec() {
  int i;
  for(i=0;i<vec.size();i++) {
    printf("%d ",vec[i]);
  }
}

int fun(int sum) {
  int i;

  // printf("Fun(%d %d)",sum,flag);
  // printVec();

  if(sum==0 && flag==0) {
    for(i=0;i<vec.size();i++) {
      printf("%d",vec[vec.size()-1-i]);
    }

    flag=1;
    return 0;
  }

  if(flag) return 0;
  if(sum>=7) {
    vec.push_back(7);
    fun(sum-7);
    vec.pop_back();
  }

  if(flag) return 0;
  if(sum>=4) {
    vec.push_back(4);
    fun(sum-4);
    vec.pop_back();
  }

  if(flag) return 0;
  else return -1;
}

int main() {
  int n;
  scanf("%d",&n);
  flag=0;
  if(fun(n)==-1) {
    printf("-1");
  }
  return 0;
}
