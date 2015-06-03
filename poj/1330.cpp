#include<cstdio>
#include<utility>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;
typedef pair<int,int> pi;
bool myfunc(pi x,int y) {
	return x.second<y;
}
bool my_funcnew(pi x,pi y) {
	return x.second<y.second;
}
void print(vector<int> x) {
	vector<int>::iterator it;
	for(it=x.begin();it!=x.end();++it)
		printf("%d ",*it);
}
int main() {
	int T,N,ele1,ele2;
	vector<pi>a;
	vector<int>l,r;
	vector<pi>::iterator it;
	pi temp;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&N);
		l.clear();r.clear();a.clear();
		while(--N) {
			scanf("%d%d",&(temp.first),&(temp.second));
			a.push_back(temp);
		}
		scanf("%d%d",&(ele1),&(ele2));
		sort(a.begin(),a.end(),my_funcnew);
		l.push_back(ele1);
		r.push_back(ele2);
		ele2=0;
		while((it=lower_bound(a.begin(),a.end(),ele1,myfunc))!=a.end()) {
			if(it->second!=ele1)
				break;
			l.push_back(it->first);
			ele1=it->first;
			//printf("%d ",ele1);
			ele2=it-a.begin();
		}
		ele2=0;
		ele1=r[0];
		while((it=lower_bound(a.begin(),a.end(),ele1,myfunc))!=a.end()) {
			if(it->second!=ele1)
				break;
			r.push_back(it->first);
			ele1=it->first;
			//printf("%d ",ele1);
			ele2=it-a.begin();
		}
		/*printf("\n");
		print(l);
		printf("\n");
		print(r);
		printf("\n");*/
		vector<int>::iterator lrit;
		for(lrit=l.begin();lrit!=l.end();++lrit) {
			if(find(r.begin(),r.end(),*lrit)!=r.end()) {
				printf("%d\n",*lrit);
				break;
			}
		}
	}
	return 0;
}
