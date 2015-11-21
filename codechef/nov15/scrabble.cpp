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

// Declaration
vector<int> vec[100010];
vi nodeValue;
string nodeTiles;
vector<pair<string,int> >words;
vi tiles;
int nodeTilesArr[26]={0};
int N,M,K,D;


// Functions
void init() {
	var(int);
	char ch;
	int N,M;
	
	// initialize nodes
	sc("%d %d",&N,&M);
	nodeValue.pb(0);
	fr(i,0,N) {
		sc("%d",&tmp);
		nodeValue.pb(tmp);
	}
	cin>>nodeTiles;
	assert(nodeTiles.lenght()==N);
	fr(i,0,N) nodeTilesArr[nodeTiles[i]-'A']++;
	
	// initialize graph
	fr(i,0,M) {
		sc("%d %d",&tmp,&tmp1);
		vec[tmp].pb(tmp1);
		vec[tmp1].pb(tmp);
	}
}

vector<pair<string,int> > getWord() {
    // 1 point: E × 12%, A × 9%, I × 9%, O × 8%, N × 6%, R × 6%, T × 6%, L × 4%, S × 4%, U × 4%
    // 2 points: D × 4%, G × 3%
    // 3 points: B × 2%, C × 2%, M × 2%, P × 2%
    // 4 points: F × 2%, H × 2%, V × 2%, W × 2%, Y × 2%
    // 5 points: K × 1%
    // 8 points: J × 1%, X × 1%
    // 10 points: Q × 1%, Z × 1%
    // 
    // return (word and node id) with highest value (w.r.t occurrence and node points) which is not yet used

}

int main() {
	var(int);
	int D;
	string W;
	sc("%d",&D);
	fr(i,0,D) cin>>W;
	init();

	return 0;
}