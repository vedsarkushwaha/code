#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
typedef unsigned long long ll;
struct node {
	int t;
	int l;
};
typedef vector<node> vn;
bool comp(node a,node b) {
	if(a.t==b.t)
		return a.l<b.l;
	else
		return a.t<b.t;
}
bool compt(node a,node b) {
	if(a.l==b.l)
		return a.t>b.t;
	else
		return a.l>b.l;
}
int main() {
	int N;
	ll sum=0,twt=0;
	vn vec;
	vn newvec;
	node ele,temp;
	int i,j,k,l;
	vn::iterator it;
	vn::iterator itt;
	double avgwt;
	scanf("%d",&N);
	for(i=0;i<N;i++) {
		scanf("%d%d",&ele.t,&ele.l);
		vec.push_back(ele);
	}
	//sort according to time of arrival
	sort(vec.begin(),vec.end(),comp);
	temp.t=vec.at(0).t;temp.l=vec.at(0).l;
	sum=temp.l+temp.t;
	twt=sum-temp.t;
	//print_vec(vec);
	it=vec.begin()+1;
	int flag;
	make_heap(newvec.begin(),newvec.end(),compt);
	while(it!=vec.end()) {
		flag=0;
		while((it!=vec.end())&&(*it).t<=sum) {
			newvec.push_back(*it);
			vec.erase(it);
			push_heap(newvec.begin(),newvec.end(),compt);
			it++;
			flag=1;
		}
		if(flag==0) {
			sum++;
			continue;
		}
		pop_heap(newvec.begin(),newvec.end(),compt);
		temp.l=(newvec.back()).l;temp.t=(newvec.back()).t;
		//cout<<" "<<temp.t<<" "<<temp.l<<endl;
		sum+=temp.l;
		twt+=(sum-temp.t);
		newvec.pop_back();
	}
	while(newvec.size()) {
		pop_heap(newvec.begin(),newvec.end(),compt);
		temp.l=(newvec.back()).l;temp.t=(newvec.back()).t;
		sum+=temp.l;
		//cout<<sum<<endl;
		twt+=(sum-temp.t);
		newvec.pop_back();
		//cout<<" "<<temp.t<<" "<<temp.l<<endl;
	}
	avgwt=(double)twt/N;
	printf("%.0lf",avgwt);
	return 0;
}
