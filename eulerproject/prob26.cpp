#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
struct node {
	int a;
	int b;
};
using namespace std;
int repeat(vector<struct node> v,struct node num) {
	vector<struct node>::iterator it;
	for(it=v.begin();it!=v.end();++it) {
		if(((*it).a==num.a)&&((*it).b==num.b))
			return 1;
	}
	return 0;
}
void prnt(vector<struct node> v) {
	int i;
	vector<struct node>::iterator it;
	for(it=v.begin();it!=v.end();++it)
		printf("%d ",(*it).b);
	printf("\n");
}
int main() {
	int i,j,k,l=0,max=0,num=0;
	struct node temp;
	vector<struct node> v;
	j=1;
	for(i=2;i<1000;i++) {
	//i=7;
		v.clear();j=1;
		//get decimal
		while(1) {
			j*=10;
			//printf("Enters while loop\n");
			k=j%i;
			//printf("%d ",k);
			if(k==0) {
				v.clear();
				break;
			}
			else {
				l=(j-k)/i;
				temp.a=k;
				temp.b=l;
				if(repeat(v,temp))
					break;
				v.push_back(temp);
				//printf("%d ",l);
			}
			j=j-(i*l);
		}
		if(max<v.size()) {
			max=v.size();
			num=i;
		}
		//printf("%d:",i);
		//prnt(v);
		//printf("%ld\n",v.size());
	}
	printf("%d ",num);
	return 0;
}
