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
using namespace std;

struct node {
    int A,B,V,C,id;
};

// D==0 not touched, D==1 picked not dropped, D==2 picked and dropped
bool comp(node x, node y) {
    return x.C>y.C;
}

int picked[100001];
// val==0 not touched, val==1 picked not dropped, val==2 picked and dropped

vector<pair<int,int> > tree[100001];
// pairs are destination and length

vector<pair<pair<int,int>,pair<int,int> > > requesTree[100001];
// pairs are <<drop location,order number>, <Weight,Value>>

// vector<pair<pair<int,int>,pair<int,int> > > dropTree[100001];
set<pair<int,int> > st;
// pairs are <node number, order id>

vector<node> request;
// node are {Source, Destination, Weight, Value, order number}

vector<pair<int,int> > finAns;
// each element contains string with (operation+item)

int parent[100001];
// parent array for traverse

vi traverse(int S, int D,int &tW, int &tL) {
    // pf("traverseEnter\n");
    // fflush(stdout);
    var(int);
    vi path;
    // pf("%d %d\n",S,D);
    int guy=S;
    int visited[100001]={0};
    stack<pair<int,int> > stk;
    stk.push(make_pair(S,0));
    visited[S]=1;
    parent[S]=-1;
    // pf("just before loop\n");
    // fflush(stdout);
    while(guy!=D) {
        guy=(stk.top()).first;
        stk.pop();
        // pf("%d\n",guy);
        // pf("traverse conn\n");
        // pf("Guy=%d\n",guy);
        // pf("GuyNeighbour=%d\n",tree[guy].size());
        // fflush(stdout);
        fr(i,0,tree[guy].size()) {
            // pf("%d\n",tree[guy][i].first);
            // fflush(stdout);
            if(!visited[tree[guy][i].first]) {
                stk.push(tree[guy][i]);
                visited[tree[guy][i].first]=1;
                parent[tree[guy][i].first]=guy;
                if(tree[guy][i].first==D) {
                    flag=1;
                    break;
                }
            }
        }
        // pf("\n");
        // pf("traverse conn end\n");
        // fflush(stdout);
        if(flag) break;
    }
    // pf("after loop\n");
    // fflush(stdout);
    guy=D;
    while(guy!=-1) {
        // pf("%d-\n",guy);
        assert(guy!=0);
        path.pb(guy);
        guy=parent[guy];
    }
    // pf("after path creation\n");
    // fflush(stdout);
    reverse(path.begin(),path.end());
    // pf("just before return\n");
    // fflush(stdout);
    return path;
}

void print() {
    var(int);
    assert(finAns[0].first==0);
    int cNode=finAns[0].first;
    fr(i,0,finAns.size()) {
        if(finAns[i].first==0) cNode=finAns[i].first;
        if(finAns[i].first=='1' && picked[cNode]==1) continue;
        pf("%d %d\n",finAns[i].first,finAns[i].second);
    }
}

int findDist(int S, int D) {
    var(int);
    fr(i,0,tree[S].size()) {
        if(tree[S][i].first==D) return tree[S][i].second;
    }
    assert(1==0);
}

int main() {
    var(int);
    int N,M,tW=0,tL=0;
    sc("%d %d",&N,&M);
    // pf("1\n");
    // fflush(stdout);
    fr(i,0,M) {
        sc("%d %d %d",&tmp1,&tmp2,&tmp3);
        tree[tmp1].pb(make_pair(tmp2,tmp3));
        tree[tmp2].pb(make_pair(tmp1,tmp3));
    }
    // pf("2\n");
    // fflush(stdout);
    int K;
    sc("%d",&K);
    int A,B,V,C,D;
    fr(i,0,K) {
        sc("%d %d %d %d",&A,&B,&V,&C);
        request.pb({A,B,V,C,i+1});
        requesTree[request[i].A].pb(make_pair(make_pair(request[i].B,i+1),make_pair(request[i].V,request[i].C)));
        // dropTree[request[i].B].pb(make_pair(make_pair(request[i].A,i+1),make_pair(request[i].V,request[i].C)));
    }
    sort(request.begin(),request.end(),comp);
    int S,L,W;
    sc("%d %d %d",&S,&L,&W);
    // path from S to A1
    // pf("=%d %d=\n",S,request[0].A);
    vi path = traverse(S,request[0].A,tW,tL);
    fr(i,1,path.size()) {
        tL+=findDist(path[i-1],path[i]);
        if(tL>L) {
            flag=1;
            break;
        }
        finAns.pb(make_pair(0,path[i]));
        
        // if(i<path.size()-1)
        if(requesTree[path[i]].size()) {
            fr(j,0,requesTree[path[i]].size()) {
                if(picked[requesTree[path[i]][j].first.second]==0 && (tW+requesTree[path[i]][j].second.first)<=W) {
                    pf("%d\n",requesTree[path[i]][j].second.first);
                    // sstm<<"1 "<<requesTree[path[i]][j].first.second;
                    finAns.pb(make_pair(1,requesTree[path[i]][j].first.second));
                    picked[requesTree[path[i]][j].first.second]=1;
                    tW+=requesTree[path[i]][j].second.first;
                }
            }
        }
        
        if(dropTree[path[i]].size()) {
            fr(j,0,dropTree[path[i]].size()) {
                if(picked[dropTree[path[i]][j].first.second]==1) {
                    pf("%d\n",dropTree[path[i]][j].second.first);
                    // sstm<<"2 "<<dropTree[path[i]][j].first.second;
                    finAns.pb(make_pair(2,dropTree[path[i]][j].first.second));
                    picked[dropTree[path[i]][j].first.second]=2;
                    tW-=dropTree[path[i]][j].second.first;
                    // assert(tW>=0);
                }
            }
        }
    }
    if(!flag)
    fr(k,0,K) {
        if(flag) break;
        // get the request
        // pf("=%d %d=\n",request[k].A,request[k].B);
        path=traverse(request[k].A,request[k].B,tW,tL);
        // pf("passed");
        // fflush(stdout);
        fr(i,1,path.size()) {
            tL+=findDist(path[i-1],path[i]);
            if(tL>L) {
                flag=1;
                break; 
            }               
            finAns.pb(make_pair(0,path[i]));
            
            // if(i<path.size()-1)
            if(requesTree[path[i]].size()) {
                fr(j,0,requesTree[path[i]].size()) {
                    if(picked[requesTree[path[i]][j].first.second]==0 && (tW+requesTree[path[i]][j].second.first)<=W) {
                        // sstm<<"1 "<<requesTree[path[i]][j].first.second;
                        finAns.pb(make_pair(1,requesTree[path[i]][j].first.second));
                        picked[requesTree[path[i]][j].first.second]=1;
                        tW+=requesTree[path[i]][j].second.first;
                    }
                }
            }
        
            if(dropTree[path[i]].size()) {
                fr(j,0,dropTree[path[i]].size()) {
                    if(picked[dropTree[path[i]][j].first.second]==1) {
                        // sstm<<"2 "<<dropTree[path[i]][j].first.second;
                        finAns.pb(make_pair(2,dropTree[path[i]][j].first.second));
                        picked[dropTree[path[i]][j].first.second]=2;
                        tW-=dropTree[path[i]][j].second.first;
                        assert(tW>=0);
                    }
                }
            }
        }
        if(!flag)
        if(k==K-1) break;

        // come to new request
        assert(picked[request[k].id]!=0);
        // pf("=%d %d=\n",request[k].B,request[k+1].A);
        path=traverse(request[k].B,request[k+1].A,tW,tL);
        fr(i,1,path.size()) {
            tL+=findDist(path[i-1],path[i]);
            if(tL>L) {
                flag=1;
                break;
            }
            // stringstream sstm;
            // sstm<<"0 "<<path[i];
            finAns.pb(make_pair(0,path[i]));
            
            // if(i<path.size()-1)
            if(requesTree[path[i]].size()) {
                fr(j,0,requesTree[path[i]].size()) {
                    if(picked[requesTree[path[i]][j].first.second]==0 && (tW+requesTree[path[i]][j].second.first)<=W) {
                        // sstm<<"1 "<<requesTree[path[i]][j].first.second;
                        finAns.pb(make_pair(1,requesTree[path[i]][j].first.second));
                        picked[requesTree[path[i]][j].first.second]=1;
                        tW+=requesTree[path[i]][j].second.first;
                    }
                }
            }
            
            if(dropTree[path[i]].size()) {
                fr(j,0,dropTree[path[i]].size()) {
                    if(picked[dropTree[path[i]][j].first.second]==1) {
                        // sstm<<"2 "<<dropTree[path[i]][j].first.second;
                        finAns.pb(make_pair(2,dropTree[path[i]][j].first.second));
                        picked[dropTree[path[i]][j].first.second]=2;
                        tW-=dropTree[path[i]][j].second.first;
                        assert(tW>=0);
                    }
                }
            }
        }

    }

    // pf("finAns\n");
    // fflush(stdout);
    print();
    // pf("ansSize=%d\n",finAns.size());
    // pf("printAns\n");
    // fflush(stdout);
    return 0;
}