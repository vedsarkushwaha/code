#include<bits/stdc++.h>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1=0,tmp2=0,tmp3=0,tmp=0,tmp4=0,tmp5=0,flag=0,T=0,N=0,Q=0
#define pb push_back
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
using namespace std;
struct node {
	int value;
	node *children[26];
};
struct tree {
	node *root;
	int cnt;
};

inline node *getNode() {
	var(int);
	node *pNode = NULL;
	pNode = (node *)malloc(sizeof(node));
	if(pNode) {
		pNode->value = 0;
		for(i = 0; i < 26; i++) {
			pNode->children[i] = NULL;
		}
	}
	return pNode;
}

inline void init(tree *ptree) {
	ptree->root = getNode();
	ptree->cnt = 0;
}

inline void insert(tree *ptree, char key[]) {
	var(int);
	tmp2 = strlen(key);
	node *iter;
	ptree->cnt++;
	iter = ptree->root; 
	for(tmp1=0;tmp1<tmp2;tmp1++) {
		tmp3=key[tmp1]-'a';
		if( !iter->children[tmp3]) {
			iter->children[tmp3] = getNode();
		}
		iter = iter->children[tmp3];
	}
	iter->value = ptree->cnt;
}

inline int search(tree *ptree, char key[]) {
	var(int);
	tmp2=strlen(key);
	node *iter; 
	iter = ptree->root;
	for(tmp1 = 0; tmp1 < tmp2; tmp1++) {
		tmp3=key[tmp1]-'a';
		if(!iter->children[tmp3]) {
			return tmp1+1;
		}
		iter = iter->children[tmp3];
	}
	return tmp2;
}
int main() {
	char key[1000010];
	var(int);
	tree tree;
	sc("%d",&T);
	fr(k,1,T+1) {
		tmp=0;
		init(&tree);
		sc("%d",&N);
		fr(i,0,N) {
			sc("%s",key);
			tmp+=search(&tree,key);
			insert(&tree, key);
		}
		pf("Case #%d: %d\n",k,tmp);
	}
	return 0;
}
