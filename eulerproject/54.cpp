#include <cstdio>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int royalFlush(vector<pair<int, char> > cards) {
  if(cards[0].first=='T' && cards[1].first=='J' && cards[2].first=='Q' && cards[3].first=='K' && cards[4].first=='Q') {
    return 5000000;
  }
  else return 0;
}

int fourOfAKind(vector<pair<int, char> > cards) {
  int i;
  int arr[300]={0};
  for(i=0;i<cards.size();i++) {
    arr[cards[i].first]++;
  }
  for(i=0;i<300;i++) if(arr[i]==4) return 500000+arr[i];
  return 0;
}

int fullHouse(vector<pair<int, char> > cards) {
  int i;
  int arr[300]={0};
  for(i=0;i<cards.size();i++) {
    arr[cards[i].first]++;
  }
  int flag1=0,flag2=0;
  for(i=0;i<300;i++) {
    if(arr[i]==3) flag1=1;
    if(arr[i]==2) flag2=1;
  }
  if(flag1 && flag2) return 100000;
  else return 0;
}

int flush(vector<pair<int, char> > cards) {
  if(cards[0][1]==cards[1][1] && cards[1][1]==cards[2][1] && cards[2][1]==cards[3][1] && cards[3][1]==cards[4][1]) {
    return 50000;
  }
  else return 0;
}

int straight(vector<pair<int, char> > cards) {
  if(cards[0][0]==cards[1][0]-1 && cards[1][0]==cards[2][0]-1 && cards[2][0]==cards[3][0]-1 && cards[3][0]==cards[4][0]-1) {
    return 10000;
  }
  else return 0;
}

bool threeOfAKind(vector<pair<int, char> > cards) {
  int i;
  int arr[300]={0};
  for(i=0;i<cards.size();i++) {
    arr[cards[i][0]]++;
  }
  for(i=0;i<300;i++) if(arr[i]==3) return 5000;
  return 0;
}

bool twoPairs(vector<pair<int, char> > cards) {
  int i;
  int arr[300]={0};
  for(i=0;i<cards.size();i++) {
    arr[cards[i][0]]++;
  }
  int cnt=0;
  for(i=0;i<300;i++) {
    if(arr[i]>=2) cnt++;
  }
  if(cnt==2) return 1000;
  else return 0;
}

bool onePair(vector<pair<int, char> > cards) {
  int i;
  int arr[300]={0};
  for(i=0;i<cards.size();i++) {
    arr[cards[i][0]]++;
  }
  int cnt=0;
  for(i=0;i<300;i++) {
    if(arr[i]>=2) return 500;
  }
  return 0;
}

bool straightFlush(vector<pair<int, char> > cards) {
  if(flush(cards) && straight(cards)) return 1000000;
  else return 0;
}

void print(vector<pair<int, char> > vec) {
  int i;
  for(i=0;i<vec.size();i++) {
    cout<<vec[i].first<<vec[i].second<<" ";
  }
}

int getVal(vector<pair<int, char> > p1) {
  return royalFlush(p1) + straightFlush(p1) + fourOfAKind(p1)+fullHouse(p1)+flush(p1)+straight(p1)+threeOfAKind(p1)+twoPairs(p1)+onePair(p1);
}

int val(char str) {
  if(str=='A') return 20;
  if(str=='K') return 19;
  if(str=='Q') return 18;
  if(str=='J') return 17;
  if(str=='T') return 16;
  return str-'1';
}

int main() {
  vector<pair<int, char> >p1;
  vector<pair<int, char> >p2;
  string tmp;
  int valp1=0;
  int valp2=0;
  int i;
  for(i=0;i<5;i++) {
    cin>>tmp;
    p1.push_back(make_pair(val(tmp[0]),tmp[1]));
  }
  sort(p1.begin(),p1.end());
  print(p1);
  for(i=0;i<5;i++) {
    cin>>tmp;
    p1.push_back(make_pair(val(tmp[0]),tmp[1]));
  }
  sort(p2.begin(),p2.end());
  print(p2);

  printf("Royal Flush: %d\n", royalFlush(p1));
  printf("straightFlush: %d\n", straightFlush(p1));
  printf("fourOfAKind: %d\n", fourOfAKind(p1));
  printf("fullHouse: %d\n", fullHouse(p1));
  printf("flush: %d\n", flush(p1));
  printf("straight: %d\n", straight(p1));
  printf("threeOfAKind: %d\n", threeOfAKind(p1));
  printf("twoPairs: %d\n", twoPairs(p1));
  printf("onePair: %d\n", onePair(p1));

  printf("Royal Flush: %d\n", royalFlush(p2));
  printf("straightFlush: %d\n", straightFlush(p2));
  printf("fourOfAKind: %d\n", fourOfAKind(p2));
  printf("fullHouse: %d\n", fullHouse(p2));
  printf("flush: %d\n", flush(p2));
  printf("straight: %d\n", straight(p2));
  printf("threeOfAKind: %d\n", threeOfAKind(p2));
  printf("twoPairs: %d\n", twoPairs(p2));
  printf("onePair: %d\n", onePair(p2));

  valp1 = getVal(p1);
  valp2 = getVal(p2);
  if(valp1>valp2) printf("1");
  else if(valp2>valp1) printf("2");
  else {
    for(i=4;i>=0;i--) {
      if(val(p1[i])>val(p2[i])) {
        printf("1");
        break;
      }
      else if(val(p2[i])>val(p1[i])) {
        printf("2");
        break;
      }
    }
  }
  return 0;
}
