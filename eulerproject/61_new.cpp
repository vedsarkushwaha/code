#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <cassert>

using namespace std;
int arr[10000000];

int fun3(int n) {
  return (n*(n+1))/2;
}

int fun4(int n) {
  return n*n;
}

int fun5(int n) {
  return (n*(3*n-1))/2;
}

int fun6(int n) {
  return (n*(2*n-1));
}

int fun7(int n) {
  return (n*(5*n-3))/2;
}

int fun8(int n) {
  return n*(3*n-2);
}

bool chkDig(int num) {
  int cnt=0;
  while(num!=0) {
    cnt++;
    num/=10;
  }
  return cnt==4;
}

vector<pair<int,int> > vec;

bool chk(int a,int b,int c,int d,int e,int f) {
  int arr[10]={0};
  arr[a]+=1;
  arr[b]+=1;
  arr[c]+=1;
  arr[d]+=1;
  arr[e]+=1;
  arr[f]+=1;
  for(int i=0;i<10;i++) {
    if(arr[i]>1) return false;
  }
  return true;
}

int main() {
  int i=1,j,k,l,m,n;

  while(!chkDig(fun3(++i)));
  while(chkDig(fun3(++i))) {
    if(fun3(i)%100<10) continue;
    vec.push_back(make_pair(fun3(i),3));
    i++;
  }
  printf("%d\n",vec.size());

  i=1;
  while(!chkDig(fun4(++i)));
  while(chkDig(fun4(++i))) {
    if(fun4(i)%100<10) continue;
    vec.push_back(make_pair(fun4(i),4));
    i++;
  }

  i=1;
  while(!chkDig(fun5(++i)));
  while(chkDig(fun5(++i))) {
    if(fun5(i)%100<10) continue;
    vec.push_back(make_pair(fun5(i),5));
    i++;
  }

  i=1;
  while(!chkDig(fun6(++i)));
  while(chkDig(fun6(++i))) {
    if(fun6(i)%100<10) continue;
    vec.push_back(make_pair(fun6(i),6));
    i++;
  }

  i=1;
  while(!chkDig(fun7(++i)));
  while(chkDig(fun7(++i))) {
    if(fun7(i)%100<10) continue;
    vec.push_back(make_pair(fun7(i),7));
    i++;
  }

  while(!chkDig(fun8(++i)));
  while(chkDig(fun8(++i))) {
    if(fun8(i)%100<10) continue;
    vec.push_back(make_pair(fun8(i),8));
    i++;
  }

  int flag3=0;
  int flag4=0;
  int flag5=0;
  int flag6=0;
  int flag7=0;
  int flag8=0;

  printf("%d\n",vec.size());
  for(i=0;i<vec.size();i++) {
    int af=vec[i].first/100;int al=vec[i].first%100;
    j=((i<48)?48:0);
    for(;j<vec.size();j++) {
      int bf=vec[j].first/100;int bl=vec[j].first%100;
      k=((i<48)?48:0);
      for(;k<vec.size();k++) {
        int cf=vec[k].first/100;int cl=vec[k].first%100;
        l=((i<48)?48:0);
        for(;l<vec.size();l++) {
          int df=vec[l].first/100;int dl=vec[l].first%100;
          m=((i<48)?48:0);
          for(;m<vec.size();m++) {
            int ef=vec[m].first/100;int el=vec[m].first%100;
            n=((i<48)?48:0);
            for(;n<vec.size();n++) {
              int ff=vec[n].first/100;int fl=vec[n].first%100;
              if(chk(vec[i].second,vec[j].second,vec[k].second,vec[l].second,vec[m].second,vec[n].second)) {
                if(al==bf && bl==cf && cl==df && dl==ef && el==ff && fl==af) {
                  printf("%d\n",vec[i].first);
                  printf("%d\n",vec[j].first);
                  printf("%d\n",vec[k].first);
                  printf("%d\n",vec[l].first);
                  printf("%d\n",vec[m].first);
                  printf("%d\n",vec[n].first);
                }
              }
            }
          }
        }
      }
    }
  }
  return 0;
}
