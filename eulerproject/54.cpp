#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <cassert>

using namespace std;

int val(char ch) {
  if(ch=='A') return 14;
  if(ch=='K') return 13;
  if(ch=='Q') return 12;
  if(ch=='J') return 11;
  if(ch=='T') return 10;
  return ch-'0';
}

// if equal flush then get highest card until difference happens
int flush(vector<pair<int, char> > cards) {
  if(cards[0].second==cards[1].second && cards[1].second==cards[2].second && cards[2].second==cards[3].second && cards[3].second==cards[4].second) {
    return 50000;
  }
  else return 0;
}

// no chance of highest
int royalFlush(vector<pair<int, char> > cards) {
  if(cards[0].first==10 && cards[1].first==11 && cards[2].first==12 && cards[3].first==13 && cards[4].first==14 && flush(cards)) {
    return 5000000;
  }
  else return 0;
}

// no chance of highest
int fourOfAKind(vector<pair<int, char> > cards) {
  int i,val;
  int arr[300]={0};
  for(i=0;i<cards.size();i++) {
    arr[cards[i].first]++;
  }
  for(i=0;i<300;i++) {
    if(arr[i]==4) {
      val = 500000+100*i;
      if(cards[4].first != i) {
        return val+cards[4].first;
      }
      else if(cards[3].first != i) {
        return val+cards[3].first;
      }
      else if(cards[2].first != i) {
        return val+cards[2].first;
      }
      else if(cards[1].first != i) {
        return val+cards[1].first;
      }
      else {
        return val+cards[0].first;
      }
    }
  }
  return 0;
}

// no chance of highest
int fullHouse(vector<pair<int, char> > cards) {
  int i;
  int arr[300]={0};
  for(i=0;i<cards.size();i++) {
    arr[cards[i].first]++;
  }
  int flag1=0,flag2=0;
  for(i=0;i<300;i++) {
    if(arr[i]==3) flag1=i;
    if(arr[i]==2) flag2=i;
  }
  if(flag1 && flag2) return 100000+100*flag1+flag2;
  else return 0;
}

// no chance of highest
int straight(vector<pair<int, char> > cards) {
  if(cards[0].first==cards[1].first-1 && cards[1].first==cards[2].first-1 && cards[2].first==cards[3].first-1 && cards[3].first==cards[4].first-1) {
    return 10000+cards[4].first;
  }
  else return 0;
}

// no chance of highest
int threeOfAKind(vector<pair<int, char> > cards) {
  int i,val;
  int arr[300]={0};
  for(i=0;i<cards.size();i++) {
    arr[cards[i].first]++;
  }
  for(i=0;i<300;i++) {
    if(arr[i]==3) {
      val = 5000000+10000*i;
      if(cards[4].first!=i) {
        val+=(100*cards[4].first);
      }
      if(cards[3].first!=i) {
        if(val==5000000+10000*i) val+=(100*cards[3].first);
        else return val+cards[3].first;
      }
      if(cards[2].first!=i) {
        if(val==5000000+10000*i) val+=(100*cards[2].first);
        else return val+cards[2].first;
      }
      if(cards[1].first!=i) {
        if(val==5000000+10000*i) val+=(100*cards[1].first);
        else return val+cards[1].first;
      }
      if(cards[0].first!=i) {
        assert(val!=(5000000+10000*i));
        return val+cards[0].first;
      }
    }
  }
  return 0;
}

// no chance of highest
int twoPairs(vector<pair<int, char> > cards) {
  int i,f1,f2,val;
  int arr[300]={0};
  for(i=0;i<cards.size();i++) {
    arr[cards[i].first]++;
  }
  int cnt=0;
  for(i=0;i<300;i++) {
    if(arr[i]==2) {
      if(cnt==0) f1=i;
      if(cnt==1) f2=i;
      cnt++;
    }
  }
  if(cnt==2) {
    val = 1000000+10000*f2+100*f1;
    for(i=4;i>=0;i--) {
      if(cards[i].first!=f1 && cards[i].first!=f2) return val+cards[i].first;
    }
    assert(1==0);
  }
  else return 0;
}

// no chance of highest
int onePair(vector<pair<int, char> > cards) {
  int i,val,j;
  int arr[300]={0};
  for(i=0;i<cards.size();i++) {
    arr[cards[i].first]++;
  }
  int cnt=0;
  for(i=0;i<300;i++) {
    if(arr[i]==2) {
      val = 500000000+1000000*i;
      for(j=4;j>=0;j--) {
        if(cards[j].first!=i) {
          if(cnt==0) val+=cards[j].first*10000;
          if(cnt==1) val+=cards[j].first*100;
          if(cnt==2) return val+=cards[j].first;
          cnt++;
        }
      }
      assert(1==0);
    }
  }
  return 0;
}

// no chance of highest
int straightFlush(vector<pair<int, char> > cards) {
  int tmp1,tmp2;
  tmp1=flush(cards);
  tmp2=straight(cards);
  if(tmp1 && tmp2) return tmp1+tmp2;
  else return 0;
}

// no chance of highest
int highestCard(vector<pair<int, char> > cards) {
  return cards[4].first;
}

void print(vector<pair<int, char> > vec) {
  int i;
  for(i=0;i<vec.size();i++) {
    cout<<vec[i].first<<vec[i].second<<" ";
  }
  printf("\n");
}

int main() {
  vector<pair<int, char> >p1;
  vector<pair<int, char> >p2;
  string tmp;
  int i,cnt1=0;
  int t=1000;
  while(t--) {
    p1.clear();
    p2.clear();
    for(i=0;i<5;i++) {
      cin>>tmp;
      p1.push_back(make_pair(val(tmp[0]),tmp[1]));
    }
    sort(p1.begin(),p1.end());
    print(p1);
    for(i=0;i<5;i++) {
      cin>>tmp;
      p2.push_back(make_pair(val(tmp[0]),tmp[1]));
    }
    sort(p2.begin(),p2.end());
    print(p2);

    if(royalFlush(p1) > royalFlush(p2)) {
      cnt1++;
    }
    else if(royalFlush(p1) < royalFlush(p2)) {
      continue;
    }
    else if(straightFlush(p1) > straightFlush(p2)) {
      cnt1++;
    }
    else if(straightFlush(p1) < straightFlush(p2)) {
      continue;
    }
    else if(fourOfAKind(p1) > fourOfAKind(p2)) {
      cnt1++;
    }
    else if(fourOfAKind(p1) < fourOfAKind(p2)) {
      continue;
    }
    else if(fullHouse(p1) > fullHouse(p2)) {
      cnt1++;
    }
    else if(fullHouse(p1) < fullHouse(p2)) {
      continue;
    }
    else if(flush(p1) > flush(p2)) {
      cnt1++;
    }
    else if(flush(p1) < flush(p2)) {
      continue;
    }
    else if(straight(p1) > straight(p2)) {
      cnt1++;
    }
    else if(straight(p1) < straight(p2)) {
      continue;
    }
    else if(threeOfAKind(p1) > threeOfAKind(p2)) {
      cnt1++;
    }
    else if(threeOfAKind(p1) < threeOfAKind(p2)) {
      continue;
    }
    else if(twoPairs(p1) > twoPairs(p2)) {
      cnt1++;
    }
    else if(twoPairs(p1) < twoPairs(p2)) {
      continue;
    }
    else if(onePair(p1) > onePair(p2)) {
      cnt1++;
    }
    else if(onePair(p1) < onePair(p2)) {
      continue;
    }
    else if(highestCard(p1) > highestCard(p2)) {
      cnt1++;
    }
    else if(highestCard(p1) < highestCard(p2)) {
      continue;
    }
    // printf("Royal Flush: %d\n", royalFlush(p1));
    // printf("straightFlush: %d\n", straightFlush(p1));
    // printf("fourOfAKind: %d\n", fourOfAKind(p1));
    // printf("fullHouse: %d\n", fullHouse(p1));
    // printf("flush: %d\n", flush(p1));
    // printf("straight: %d\n", straight(p1));
    // printf("threeOfAKind: %d\n", threeOfAKind(p1));
    // printf("twoPairs: %d\n", twoPairs(p1));
    // printf("onePair: %d\n", onePair(p1));
    // printf("highestCard: %d\n", highestCard(p1));
    //
    // printf("Royal Flush: %d\n", royalFlush(p2));
    // printf("straightFlush: %d\n", straightFlush(p2));
    // printf("fourOfAKind: %d\n", fourOfAKind(p2));
    // printf("fullHouse: %d\n", fullHouse(p2));
    // printf("flush: %d\n", flush(p2));
    // printf("straight: %d\n", straight(p2));
    // printf("threeOfAKind: %d\n", threeOfAKind(p2));
    // printf("twoPairs: %d\n", twoPairs(p2));
    // printf("onePair: %d\n", onePair(p2));
    // printf("highestCard: %d\n", highestCard(p2));
  }
  printf("%d\n",cnt1);
  return 0;
}
