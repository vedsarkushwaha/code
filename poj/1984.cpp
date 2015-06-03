#include<algorithm>
#include<cstdio>
#include<vector>
class node {
	int v1,v2,l;
	char d;
};
class comp {
	int x,y;
	bool set,q_ind;
	void node() {
		set=false;
		q_ind=false;
	}
};
class q_c {
	int nd1,nd2,farm_i,q_i;
};
bool srt_farmi(q_c a, q_c b) {
	return a.farm_i<b.farm_i;
}
bool srt_qi(q_c a, q_c b) {
	return a.q_i<b.q_i;
}
void get_xy(comp *f,int n1,int n2,int l,int d,int *x,int *y) {
	if(d=='E') {
		*x=f[n1].x+l;
		*y=f[n1].y;
	}
	else if(d=='W') {
		*x=f[n1].x-l;
		*y=f[n1].y;
	}
	else if(d=='N') {
		*y=f[n1].y+l;
		*x=f[n1].x;
	}
	else if(d=='S') {
		*y=f[n1].y-l;
		*x=f[n1].x;
	}
}
using namespace std;
int main() {
	int N,M;
	int i,n1,n2,len,dir,ax,ay;
	node temp;
	scanf("%d%d",&N,&M);
	comp farm[N];
	vector<vector<node>>rem(N);
	if(M>0) {
		scanf("%d%d%d%c",&n1,&n2,&len,&dir);
		farm[n1].x=0;farm[n1].y=0;farm[n1].set=true;
		get_xy(farm,n1,n2,len,dir,&x,&y);
		farm[n2].x=x;farm[n2].y=y;farm[n2].set=true;
	}
	for(i=1;i<M;i++) {
		scanf("%d%d%d%c",&n1,&n2,&len,&dir);
		if(farm[n1].set==true) {
			get_xy(farm,n1,n2,len,dir,&x,&y);
			farm[n2].x=x;farm[n2].y=y;farm[n2].set=true;
		}
		else if(farm[n2].set==true) {
			get_xy(farm,n2,n1,len,dir,&x,&y);
			farm[n1].x=x;farm[n1].y=y;farm[n1].set=true;
		}
		else {
			temp.v1=n1;temp.v2=n2;temp.l=len;temp.d=dir;
			rem[n1].push_back(temp);
			rem[n2].push_back(temp);
		}
	}
	scanf("%d",&Q);
	int Q;
	vector<q_c> que;
	q_c temp1;
	for(i=0;i<Q;i++) {
		scanf("%d%d%d",&(temp1.nd1),&(temp1.nd2),&(temp1.farm_i));temp.qi=i;
		sort(que.begin(),que.end(),srt_farmi);
		
