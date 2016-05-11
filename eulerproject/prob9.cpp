#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

map<int,int> sqr;

int chkInt(int i, int j) {
    int tmp = (i*i + j*j);
    if(sqr.find(tmp)!=sqr.end()) {
        return (sqr.find(tmp))->second;
    }
    else {
        return 0;
    }
}

int main() {
    int T,N,i,j,tmp;
    // scanf("%d",&T);
    // init
    map<int,vector<int> > mp;
    map<int,vector<int> >::iterator it;
    vector<int>::iterator vecIt;
    
    for(i=1;i<=3000;i++) sqr.insert(make_pair(i*i,i));
    
    for(i=1;i<=3000;i++) {
        for(j=1;j<=i;j++) {
            tmp=chkInt(i,j);
            if(tmp) {
                it=mp.find(i+j+tmp);
                if(it==mp.end()) {
                    //initialize vector and create new element
                    vector<int> tmpVec;
                    tmpVec.push_back(i*j*tmp);
                    mp.insert(make_pair(i+j+tmp,tmpVec));
                }
                else {
                    (it->second).push_back(i*j*tmp);
                }
            }
        }
    }
    int newTmp=0;
    // while(T--) {
    for(N=1;N<=3000;N++) {
        // scanf("%d",&N);
        it=mp.find(N);
        if(it==mp.end()) printf("-1\n");
        else {
            printf("%d\n",*max_element((it->second).begin(),(it->second).end()));
            // vecIt = (it->second).begin();
            // while(vecIt!=(it->second).end()) {
            //     printf("%d ",*vecIt);
            //     newTmp = max(newTmp,*vecIt);
            //     vecIt++;
            // }
        }
        // printf("\n");
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    // printf(" ==%d==",newTmp);
    return 0;
}