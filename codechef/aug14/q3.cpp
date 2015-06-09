#include<cstdio>
#include<iostream>
#include<vector>
#include<stack>
#include<map>
#include<set>
#include<cstring>
#include<cmath>
#include<string>
#include<cstdlib>
#include<queue>
#include<algorithm>
#include<climits>
#define f(i,m,n) for(i=m;i<n;i++)
#define ull unsigned long long
#define sc scanf
#define pf printf
#define dec(x) x i,j,k,tmp1,tmp2,tmp3,T,N,M
using namespace std;

using std::string;
 
static struct IO {
char tmp[1 << 10];
 
// fast input routines
char cur;
 
//#define nextChar() (cur = getc_unlocked(stdin))
//#define peekChar() (cur)
inline char nextChar() { return cur = getc_unlocked(stdin); }
inline char peekChar() { return cur; }
 
inline operator bool() { return peekChar(); }
inline static bool isBlank(char c) { return (c < '-' && c); }
inline bool skipBlanks() { while (isBlank(nextChar())); return peekChar() != 0; }
 
inline IO& operator >> (char & c) { c = nextChar(); return *this; }
 
inline IO& operator >> (char * buf) {
if (skipBlanks()) {
if (peekChar()) {
*(buf++) = peekChar();
while (!isBlank(nextChar())) *(buf++) = peekChar();
} *(buf++) = 0; } return *this; }
 
inline IO& operator >> (string & s) {
if (skipBlanks()) {	s.clear(); s += peekChar();
while (!isBlank(nextChar())) s += peekChar(); }
return *this; }
 
inline IO& operator >> (double & d) { if ((*this) >> tmp) sscanf(tmp, "%lf", &d); return *this;	}
 
#define defineInFor(intType) \
inline IO& operator >>(intType & n) { \
if (skipBlanks()) { \
int sign = +1; \
if (peekChar() == '-') { \
sign = -1; \
n = nextChar() - '0'; \
} else \
n = peekChar() - '0'; \
while (!isBlank(nextChar())) { \
n += n + (n << 3) + peekChar() - 48; \
} \
n *= sign; \
} \
return *this; \
}
 
defineInFor(int)
defineInFor(unsigned int)
defineInFor(long long)
 
// fast output routines
 
//#define putChar(c) putc_unlocked((c), stdout)
inline void putChar(char c) { putc_unlocked(c, stdout); }
inline IO& operator << (char c) { putChar(c); return *this; }
inline IO& operator << (const char * s) { while (*s) putChar(*s++); return *this; }
 
inline IO& operator << (const string & s) { for (int i = 0; i < (int)s.size(); ++i) putChar(s[i]); return *this; }
 
char * toString(double d) { sprintf(tmp, "%lf%c", d, '\0'); return tmp; }
inline IO& operator << (double d) { return (*this) << toString(d); }
 
 
#define defineOutFor(intType) \
inline char * toString(intType n) { \
char * p = (tmp + 30); \
if (n) { \
bool isNeg = 0; \
if (n < 0) isNeg = 1, n = -n; \
while (n) \
*--p = (n % 10) + '0', n /= 10; \
if (isNeg) *--p = '-'; \
} else *--p = '0'; \
return p; \
} \
inline IO& operator << (intType n) { return (*this) << toString(n); }
 
defineOutFor(int)
defineOutFor(long long)
 
#define endl ('\n')
#define cout __io__
#define cin __io__
} __io__;


void init(int *a,int len,int val) {
	int i;
	f(i,0,len)
		a[i]=val;
}
void print(ull *a,int len) {
	int i;
	f(i,0,len)
		printf("%llu",a[i]);
}
struct node {
	int n,c;
};
	
int main() {
	dec(int);
	cin>>N>>M;
	vector<node> vec[N];
	vector<node>::iterator it;
	int dist[N];
	//pf("ved");
	node tt1,tt2,tt3;
	
	init(dist,N,INT_MAX);
	dist[0]=0;
	stack<int> stk;
	//fflush(stdout);
	//tmp3=M;
	while(M--) {
		cin>>tmp1>>tmp2;
		tt1.n=tmp1-1;tt2.n=tmp2-1;
		tt1.c=1;tt2.c=0;
		vec[tmp1-1].push_back(tt2);
		vec[tmp2-1].push_back(tt1);
	}
	stk.push(0);
	while(!stk.empty()) {
		tmp1=stk.top();
		//pf("%d ",tmp1);
		//fflush(stdout);
		stk.pop();
		for(it=vec[tmp1].begin();it!=vec[tmp1].end();it++) {
			//pf("%d %d\n",*it,tmp1);
			//pf("%d %d",dist[*it],dist[tmp1]);
			if(dist[(*it).n]>(dist[tmp1]+(*it).c)) {
				//pf("if");
				dist[(*it).n]=dist[tmp1]+(*it).c;
				stk.push((*it).n);
			}
		}
	}
	//for(i=0;i<tmp3;i++)
		//pf("%d ",dist[i]);
	if(dist[N-1]==INT_MAX)
		pf("-1");
	else
		pf("%d",dist[N-1]);
	return 0;
}