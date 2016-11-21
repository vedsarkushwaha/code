#include <cstdio>
#include <set>
using namespace std;

int fact[10];
int val[1000001];

int getDFS(int i) {
  int sm=0;
  // printf("i=%d: ",i);
  while(i!=0) {
    sm+=fact[i%10];
    i=i/10;
  }
  // printf("%d\n",sm);
  return sm;
}

int main() {
  int i,j,k;
  int tmp;
  fact[0]=1;
  fact[1]=1;
  for(i=2;i<10;i++) {
    fact[i]=fact[i-1]*i;
  }

  // for(i=1;i<10;i++) printf("%d ",fact[i]);
  // printf("\n");

  for(i=1;i<=1000000;i++) {
    // i=169;
    set<int> st;
    tmp = i;
    st.insert(tmp);
    do {
      // printf("%d ",tmp);
      tmp = getDFS(tmp);
      if(st.find(tmp)!=st.end()) {
        val[i]=st.size();
        break;
      }
      else if(tmp<1000000 && val[tmp]!=0) {
        val[i]=val[tmp]+st.size();
        break;
      }
      else {
        st.insert(tmp);
      }
    } while(1);
  }

  // for(i=1;i<=100;i++) printf("%d-",val[i]);
  // printf("%d\n",val[169]);
  // printf("%d\n",val[69]);
  // printf("%d\n",val[78]);

  int cnt=0;
  for(i=0;i<1000000;i++) {
    if(val[i]==60) cnt++;
  }
  printf("cnt=%d\n",cnt);

  return 0;
}
