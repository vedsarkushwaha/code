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
#define fr(i,m,n) for(i=m;i<n;i++)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1,tmp2,tmp3,tmp=0
using namespace std;
int main() {
	var(int);
	char top[100000];
	char *tt;
	int combi,sli;
	ll sum=0;
	map<string,int> mp;
	mp.insert(pair<string,int>("Anchovies",50));
	mp.insert(pair<string,int>("Artichoke",60));
	mp.insert(pair<string,int>("Bacon",92));
	mp.insert(pair<string,int>("Broccoli",24));
	mp.insert(pair<string,int>("Cheese",80));
	mp.insert(pair<string,int>("Chicken",30));
	mp.insert(pair<string,int>("Feta",99));
	mp.insert(pair<string,int>("Garlic",8));
	mp.insert(pair<string,int>("Ham",46));
	mp.insert(pair<string,int>("Jalapeno",5));
	mp.insert(pair<string,int>("Meatballs",120));
	mp.insert(pair<string,int>("Mushrooms",11));
	mp.insert(pair<string,int>("Olives",25));
	mp.insert(pair<string,int>("Onions",11));
	mp.insert(pair<string,int>("Pepperoni",80));
	mp.insert(pair<string,int>("Peppers",6));
	mp.insert(pair<string,int>("Pineapple",21));
	mp.insert(pair<string,int>("Ricotta",108));
	mp.insert(pair<string,int>("Sausage",115));
	mp.insert(pair<string,int>("Spinach",18));
	mp.insert(pair<string,int>("Tomatoes",14));
	string str;
	sc("%d",&combi);
	while(combi--) {
		sc("%d ",&sli);
		sc("%s",top);
		//pf("%d %s\n",sli,top);
		tt=strtok(top,",");
		tmp=0;
		while(tt!=NULL) {
			string chn(tt);
			tmp+=mp[tt];
			//pf("%s\n",tt);
			tt=strtok(NULL,",");
		}
		sum+=(long long)((270+tmp)*sli);
		//pf("%d\n",tmp);
	}
	pf("The total calorie intake is %lld\n",sum);
	return 0;
}
