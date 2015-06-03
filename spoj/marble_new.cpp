#include<iostream>
#include<stdlib.h>

using namespace std;

class B{
   long long int i,j,k,N,K,temp;
  public:
    void input(){
         cin>>N>>K;
         N--;
         K--;
         
    }
    void calc(){
       i=N-K;
       if(N==K||K==0) {tmp=1;}
       else if(K==1){tmp=N;}
       else  if(i>K)
       {
          j=1;
          tmp=1;
          
          while(j<=K)
          {
            if(N%j==0)
            tmp=tmp*(N/j);
            else if(tmp%j==0)
             tmp=N*(tmp/j);
            else tmp=(N*tmp)/j;
             
            j++;
            N--;
         
          }
        }
        else if(i<=K)
        {     
           j=1;
           tmp=1;
          while(j<=i)
          {
            if(N%j==0)
            tmp=tmp*(N/j);
            else if(tmp%j==0)
            tmp=N*(tmp/j);
            else tmp=(N*tmp)/j;
            j++;
            N--;
           }
         }
       }
      void output(){
         cout<<tmp<<endl;
      }
};

int main()
{
  B a;
  int T;
  cin>>T;
  while(T--){
    a.input();
    a.calc();
    a.output();
  }

return 0;
}
