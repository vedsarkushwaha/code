#include <cstdio>
#include <map>
#include <vector>
#include <cmath>
#include <set>
#include <climits>

#define L 1000000

using namespace std;

// num, {cycleLenght, smallestNumber}
pair<int,int> arr[L+1];
map<int,int> mp;

int getDivSum(int num) {
  int i;
  int limit=sqrt(num)+1;
  int divSum=0;
  for(i=1;i<limit;i++) {
    if(num%i==0) {
      if(i==num/i || num/i==num) divSum+=i;
      else divSum+=(i+num/i);
    }
  }
  return divSum;
}

void init() {
  int i;
  for(i=0;i<=L;i++) {
    arr[i].first=-1;
    arr[i].second=-1;
  }
}

int main() {
  int i,tmp;
  map<int,int>::iterator it;
  init();
  vector<int> vec;
  for(i=1;i<=L;i++) {
    tmp=i;
    int cycleSize=0;
    int minNumer=INT_MAX;
    int cnt=1;
    mp.clear();
    vec.clear();
    // start sequence with tmp
    while(1) {
      if(arr[tmp].first!=-1) {
        cycleSize=arr[tmp].first;
        minNumer=arr[tmp].second;
        break;
      }
      else {
        it = mp.find(tmp);
        if(it!=mp.end()) {
          cycleSize = mp.size() - (it)->second + 1;
          for(i=(it)->second;i<vec.size();i++) {
            minNumer=min(minNumer, vec[i]);
          }
          break;
        }
        else {
          mp.insert(make_pair(tmp,cnt));
          tmp = getDivSum(tmp);
          cnt++;
        }
      }
    }
    // insert set value to array
    for(i=0;i<vec.size();i++) {
      arr[vec[i]].first=cycleSize;
      arr[vec[i]].second=minNumer;
    }
  }

  int maxCycleLength=0;
  int ans=INT_MAX;
  for(i=1;i<=L;i++) {
    if(arr[i].first>maxCycleLength) {
      maxCycleLength=arr[i].first;
      ans=arr[i].second;
    }
    else if(arr[i].first==maxCycleLength) {
      ans=min(ans, arr[i].second);
    }
  }

  printf("%d\n",ans);
  return 0;
}
