#include<bits/stdc++.h>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1=0,tmp2=0,tmp3=0,tmp=0,tmp4=0,tmp5=0,flag=0
#define pb push_back
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
#define endl '\n'

using namespace std;

struct trie {
    int n;
    int nodes[10000000][2];

    void clear() {
        n=1;
        nodes[0][0]=nodes[0][1] = -1;
    }
    void insert(int x) {
        var(int);
        ifr(i,31,-1) {
            tmp=(x&(1<<i))!=0;
            if(nodes[tmp5][tmp]==-1) {
                nodes[tmp5][tmp]=n;
                nodes[n][0]=nodes[n][1]=-1;
                n++;
            }
            tmp5=nodes[tmp5][tmp];
        }
    }
    int query(int x) {
        var(int);
        ifr(i,31,-1) {
            int next=(x&(1<<i))!=0;
            int cool=1;
            if (nodes[tmp5][next^1]==-1) {
                next^=1;
                cool=0;
            }
            if(cool) tmp+=(1<<i);
            tmp5=nodes[tmp5][next^1];
        }
        return tmp;
    }
};
trie tree;

int main() {
    var(int);
    int N;
    sc("%d",&N);
    int leftBest[N],rightBest[N],input[N];
    fr(i,0,N) {
        leftBest[i]=0;
        rightBest[i]=0;
        sc("%d",input+i);
    }
    
    // left side
    tree.clear();
    tree.insert(0);
    int best = 0, accum = 0, t;
    fr(i,0,N) {
        accum ^= input[i];
        leftBest[i] = max(best, tree.query(accum));
        tree.insert(accum);
    }

    // right side
    tree.clear();
    tree.insert(0);
    best = 0, accum = 0;
    ifr(i,N-1,-1) {
        accum ^= input[i];
        rightBest[i] = max(best, tree.query(accum));
        tree.insert(accum);
    }
    // fr(i,0,N) pf("%d ",leftBest[i]);
    // pf("\n");
    // fr(i,0,N) pf("%d ",rightBest[i]);
    // pf("\n");
    fr(i,1,N) {
        leftBest[i]=max(leftBest[i-1],leftBest[i]);
    }
    ifr(i,N-2,-1) {
        rightBest[i]=max(rightBest[i],rightBest[i+1]);
    }
    // fr(i,0,N) pf("%d ",leftBest[i]);
    // pf("\n");
    // fr(i,0,N) pf("%d ",rightBest[i]);
    // pf("\n");
    best=0;
    fr(i,0,N-1) {
        best=max(best,leftBest[i]+rightBest[i+1]);
    }
    pf("%d",best);
    return 0;
}