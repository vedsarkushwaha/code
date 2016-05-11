

#include <iostream>
#include<iomanip>
#include<stdio.h>
#include<math.h>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#include<string.h>
#include<cstdio>
#include<vector>
#include<utility>
#include<map>

#define scl(t) scanf("%ld",&t)
#define scll(t) scanf("%lld",&t)
#define sc(t) scanf("%d",&t)
#define scf(t) scanf("%f",&t)

#define max(a,b) (a>=b?a:b)
#define min(a,b) (a<b?a:b)
#define ll long long
#define MOD 1000000007
#define gc getchar_unlocked
#define printAr(a,n) for(i=0;i<n;i++){cout<<a[i]<<" ";}
#define printMat(a,n,m) for(i=0;i<n;i++){for(j=0;j<m;j++){if(i>j)cout<<" ";else cout<<a[i][j]<<" ";}lc;}
#define mp make_pair
#define pb push_back
#define lc printf("\n")
#define inf 1000000000
#define ALPH_SIZE 10
using namespace std;

// structure define a node of Trie
struct tnode
{
    int words; //define if a node is a leaf or not
    int prefix; 
    tnode *child[ALPH_SIZE]; // links to various children

};
// structure for the root node
struct trie
{
    tnode *root;
    int count;// total no of words
};
// function to create a node and return its pointer
tnode* createNode()
{
    tnode *t=(tnode *)malloc(sizeof(tnode));
    if(t)
    {
        t->words=0;
        t->prefix=0;
        for(int i=0;i<ALPH_SIZE;i++)
            t->child[i]=NULL;
    }
    return t;
}
// initialize the root node
void initialize(trie *p)
{
    p->root=createNode();
    p->count=0;
}
// insert a word(or number in this case) into the trie
void tinsert(trie *p,string s)
{
    int len=s.length();
    tnode *mov=p->root;
    p->count++;

    for(int i=0;i<len;i++)
    {
        int ind=(int)(s.at(i)-'0');
        if(!mov->child[ind])
        {
            mov->child[ind] = createNode();
        }
        mov=mov->child[ind];
        (mov->prefix)++;
    }
    // mark as words
    mov->words = p->count;
}
//count prefixes
int tcountprefixes(trie* p,string s)
{
    int len=s.length();
    tnode* mov=p->root;
    for(int i=0;i<len;i++)
    {
        int ind=(int)(s.at(i)-'0');
        if(!mov->child[ind])
        {
             return 0;
        }
        mov=mov->child[ind];
    }
    return mov->prefix;
}


int main()
{


    int test,n,i;
    char s[19];


    //ifstream f("autocomplete.txt");
    cin>>test;
    while(test--)
        {

            trie t;
            initialize(&t);
            int flag=0;
            sc(n);// input the no of words
            string ph[n+9];

            for( i=0;i<n;i++)
            {
               cin>>ph[i];
            }
            sort(ph,ph+n);
            for(i=n-1;i>=0;i--)
            {
                tinsert(&t,ph[i]);
                if(tcountprefixes(&t,ph[i])>1)
                {
                     flag=1;
                     break;
                }
            }
            
            if(flag==0)
                printf("YES\n");
            else
                printf("NO\n");
        }


}