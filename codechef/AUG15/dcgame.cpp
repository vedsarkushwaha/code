#include <vector>
#include <algorithm>
#include <cstdio>
#include <stack>
#include <map>
#include <iostream>
#include <cstdlib>
#include <climits>

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


void stockSpan(vi &input, vi &fromLeft) {
	var(int);
	stack<pair<int,int> > stk;
	stk.push(make_pair(input[0],1));
	fromLeft.pb(1);
	fr(i,1,input.size()) {
		int sum=1;
		while(!stk.empty() && stk.top().first<input[i]) {
			sum+=stk.top().second;
			stk.pop();
		}
		stk.push(make_pair(input[i],sum));
		fromLeft.pb(sum);
	}
}

void stockSpanInv(vi &input, vi &fromRight) {
	var(int);
	stack<pair<int,int> > stk;
	stk.push(make_pair(input[input.size()-1],1));
	fr(i,0,input.size()) fromRight.pb(0);
	fromRight[input.size()-1]=1;
	ifr(i,input.size()-2,-1) {
		int sum=1;
		while(!stk.empty() && stk.top().first<=input[i]) {
			sum+=stk.top().second;
			stk.pop();
		}
		stk.push(make_pair(input[i],sum));
		fromRight[i]=sum;
	}
// 	fr(i,0,fromRight.size()) pf("%d ",fromRight[i]);
// 	pf("\n");
}

int main() {
	var(int);
	int N,M;
	vi vec,lft,rgt;
	cin>>N>>M;
	fr(i,0,N) {
		cin>>tmp;
		vec.pb(tmp);
	}
	// precompute
	stockSpan(vec,lft);
	// reverse(vec.begin(),vec.end());
	stockSpanInv(vec,rgt);
	// reverse(rgt.begin(),rgt.end());
	// reverse(vec.begin(),vec.end());
	map<int,ll> mp;
	map<int,ll>::iterator it;
	fr(i,0,vec.size()) {
	    it=mp.find(vec[i]);
		if(it!=mp.end()) (it->second)+=lft[i]*rgt[i];
		else mp.insert(make_pair(vec[i],lft[i]*rgt[i]));
	}
	vi finVec;
	vi finFreq;
	finVec.pb(INT_MIN);
	finFreq.pb(0);
	for(it=mp.begin();it!=mp.end();it++) {
		finVec.pb(it->first);
		finFreq.pb(it->second ^ finFreq.back());
	}
	char ch,pl,xx;
	int sm;
	fr(i,0,M) {
		cin>>ch>>tmp>>pl>>xx;
// 		cout<<ch<<tmp<<pl<<endl;
		if(ch=='<') {
			tmp1=upper_bound(finVec.begin(),finVec.end(),tmp)-finVec.begin();
			tmp1--;
			if(finVec[tmp1]==tmp) tmp1--;
			sm=finFreq[tmp1];
		}
        else if(ch=='>') {
			vi::iterator ittt=lower_bound(finVec.begin(),finVec.end(),tmp);
			if(ittt==finVec.end()) sm=0;
			else {
    			tmp1=ittt-finVec.begin();
	    		if(finVec[tmp1]>tmp) tmp1--;
		    	sm=finFreq.back()-finFreq[tmp1];
			}
		}
		else if(ch=='=') {
			tmp1=lower_bound(finVec.begin(),finVec.end(),tmp)-finVec.begin();
			if(finVec[tmp1]==tmp) sm=finFreq[tmp1]-finFreq[tmp1-1];
			else sm=0;
		}
		if(sm&1) pf("%c",pl);
		else {
			if(pl=='C') pf("D");
			else pf("C");
		}
	}
	return 0;
}