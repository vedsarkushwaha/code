    #include <cstdlib>
    #include <cstdio>
    #include <string>
    #include <vector>
    #include <iostream>
    #include <algorithm>
    #include <set> 

    using namespace std;
     
    #define ALPHABET_SIZE (26) 
    #define CHAR_TO_INDEX(c) ((int)c - (int)'a')
     
    struct TrieNode {
        struct TrieNode *children[ALPHABET_SIZE];
        bool isLeaf;
    };
     
    struct TrieNode *getNode(void) {
        struct TrieNode *pNode = NULL; 
        pNode = (struct TrieNode *)malloc(sizeof(struct TrieNode));
        if (pNode) {
            int i;
            pNode->isLeaf = false;
            for (i=0;i<ALPHABET_SIZE;i++) pNode->children[i] = NULL;
        }
        return pNode;
    }
     
    void insert(struct TrieNode *root, string key) {
        int level;
        int length = key.length();
        int index; 
        struct TrieNode *pCrawl = root;
        for (level = 0; level < length; level++) {
            index = CHAR_TO_INDEX(key[level]);
            if(!pCrawl->children[index]) pCrawl->children[index] = getNode();
            pCrawl = pCrawl->children[index];
        }
        pCrawl->isLeaf = true;
    }
     
    string search(struct TrieNode *root, string key) {
        int level;
        int length = key.length();
        int index;
        string ans;
        struct TrieNode *pCrawl = root;
        for(level=0;level<length;level++) {
            index = CHAR_TO_INDEX(key[level]);
            if (!pCrawl->children[index]) return ans+key[level];
            else ans+=key[level];
            pCrawl = pCrawl->children[index];
        }
        return (string)"-1";
    }
     
int main() {
    struct TrieNode *root = getNode();
    int T,i;
    vector<string> blocked;
    vector<string> unblocked;
    string sym;
    string inp;
    scanf("%d",&T);
    while(T--) {
        cin>>sym>>inp;
        if(sym=="-") blocked.push_back(inp);
        else unblocked.push_back(inp);
    }
 
    set<string> filters;
    for(i=0;i<unblocked.size();i++) insert(root, unblocked[i]);
    for(i=0;i<blocked.size();i++) {
        string str = search(root, blocked[i]);
        if(str=="-1") {
            printf("-1\n");
            return 0;
        }
        filters.insert(search(root, blocked[i]));
    }
    // sort(filters.begin(),filters.end());
    printf("%u\n",filters.size());
    set<string>::iterator it;
    for(it=filters.begin();it!=filters.end();it++) {
        cout<<*it<<endl;
    }
    return 0;
}