#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <cstring>
#include <cmath>
#include <string>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <climits>
#include <cassert>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,l=0,tmp1,tmp2,tmp3,tmp
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
using namespace std;

#define ALPHABETS 10
#define CASE '0'
#define MAX_WORD_SIZE 10
  
using namespace std;
  
struct Node {
    struct Node * parent;
    struct Node * children[ALPHABETS];
    vector<int> occurrences;
};

int InsertWord(struct Node * trieTree, char * word, int index) {
    struct Node * traverse = trieTree;
    int flag=1;
    while (*word != '\0') {
        if (traverse->children[*word - CASE] == NULL) {
            flag=0;
            traverse->children[*word - CASE] = (struct Node *) calloc(1, sizeof(struct Node));
            traverse->children[*word - CASE]->parent = traverse;
        }
        traverse = traverse->children[*word - CASE];
        ++word;
        if(traverse->occurrences.size()) return 1;
    }
    traverse->occurrences.push_back(index);
    return flag;
}

int main() {
    int T,n, i,flag;
    scanf("%d\n",&T);
    while(T--) {
        struct Node * trieTree = (struct Node *) calloc(1, sizeof(struct Node));
        char word[MAX_WORD_SIZE];

        scanf("%d\n", &n);
        flag=0;
        for (i = 1; i <= n; ++i) {
            scanf("%s\n", word);
            flag=max(flag,InsertWord(trieTree, word, i));
        }
        if(flag) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}