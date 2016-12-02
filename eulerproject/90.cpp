#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

vector<string> sqr;
vector<int> leftDice;
vector<int> rightDice;
// map<vector<int> > ansMap;
// set<pair<vector<int>, vector<int> > >ansSet;

vector<int>::iterator findVec(vector<int>::iterator first, vector<int>::iterator last, int num) {

  if(num==6 || num==9) {
    while(first!=last) {
      if(*first == 6 || *first == 9) return first;
      first++;
    }
    return last;
  }
  else {
    while(first!=last) {
      if(*first == num) return first;
      first++;
    }
    return last;
  // }
}

bool chk() {
  int i;
  bool ret1=false;
  bool ret2=false;

  vector<int>::iterator lit,rit;

  for(i=0;i<sqr.size();i++) {
    ret1=true;
    ret2=true;
    int l=sqr[i][0]-'0';
    int r=sqr[i][1]-'0';
    // printf("%d %d\n",l,r);

    lit=findVec(leftDice.begin(),leftDice.end(),l);
    rit=findVec(rightDice.begin(),rightDice.end(),r);
    if(lit==leftDice.end() || rit==rightDice.end()) {
      ret1=false;
    }
    // printf("ret1=%d\n",ret1);

    lit=findVec(leftDice.begin(),leftDice.end(),r);
    rit=findVec(rightDice.begin(),rightDice.end(),l);
    if(lit==leftDice.end() || rit==rightDice.end()) {
      ret2=false;
    }
    // printf("ret2=%d\n",ret2);
    if(ret1==false && ret2==false) return false;
  }
  return true;
}

void print() {
  int i;
  for(i=0;i<leftDice.size();i++) printf("%d ", leftDice[i]);
  printf(": ");
  for(i=0;i<rightDice.size();i++) printf("%d ", rightDice[i]);
  printf("\n");
}

int main() {
  int ans=0;

  set<pair<vector<int>, vector<int> > > ansSet;

  sqr.push_back("01");
  sqr.push_back("04");
  sqr.push_back("09");
  sqr.push_back("16");
  sqr.push_back("25");
  sqr.push_back("36");
  sqr.push_back("49");
  sqr.push_back("64");
  sqr.push_back("81");

  int arr[10]={0,1,2,3,4,5,6,7,8,9};
  int i,j,tmp,cnt;

  leftDice.push_back(0);
  leftDice.push_back(5);
  leftDice.push_back(6);
  leftDice.push_back(7);
  leftDice.push_back(8);
  leftDice.push_back(9);

  rightDice.push_back(1);
  rightDice.push_back(2);
  rightDice.push_back(3);
  rightDice.push_back(4);
  rightDice.push_back(8);
  rightDice.push_back(9);

  printf("chk=%d\n",chk());

  // vector<int> vec;
  // vec.push_back(1);
  // vec.push_back(2);
  // vec.push_back(3);
  // vec.push_back(4);
  //
  // printf("%d\n",findVec(vec.begin(),vec.end(),6)-vec.begin());

  for(i=1;i<(1<<10);i++) {
    // printf("i=%d\n",i);
    // set left dice values
    tmp=i;
    cnt=0;
    leftDice.clear();
    while(tmp) {
      if(tmp&1) {
        leftDice.push_back(arr[cnt]);
        // if(arr[cnt]==6) {
        //   leftDice.push_back(9);
        // }
        // if(arr[cnt]==9) {
        //   leftDice.push_back(6);
        // }
      }
      cnt++;
      tmp=tmp>>1;
    }
    // if more than 6 1's skip
    if(leftDice.size()>6) continue;
    for(j=1;j<(1<<10);j++) {
      // printf("j=%d\n",j);
      // set right dice values
      tmp=j;
      cnt=0;
      rightDice.clear();
      while(tmp) {
        if(tmp&1) {
          rightDice.push_back(arr[cnt]);
          // if(arr[cnt]==6) {
          //   rightDice.push_back(9);
          // }
          // if(arr[cnt]==9) {
          //   rightDice.push_back(6);
          // }
        }
        cnt++;
        tmp=tmp>>1;
      }
      // if more than 6 1's skip
      if(rightDice.size()>6) continue;
      // print();
      if(chk()) {
        // printf(" yes\n");

        if((ansSet.find(make_pair(leftDice,rightDice))==ansSet.end()) && (ansSet.find(make_pair(rightDice,leftDice))==ansSet.end())) {
          ansSet.insert(make_pair(leftDice,rightDice));
          ans++;
        }
        // ansSet.insert(make_pair(leftDice,rightDice));
      }
    }
  }
  printf("%d\n",ansSet.size());
  return 0;
}
