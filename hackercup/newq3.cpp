#include<bits/stdc++.h>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1=0,tmp2=0,tmp3=0,tmp=0,tmp4=0,tmp5=0,flag=0,T=0,N=0,Q=0,M=0
#define pb push_back
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
using namespace std;
struct node {
	char item;
	int dist;
	int dang[4];
};
int main() {
	var(int);
	pair<int,int> st,en,ptmp1,ptmp2;
	node tmpnde;
	char ch;
	sc("%d",&T);
	fr(tmp4,1,T+1) {
		sc("%d %d\n",&M,&N);
		node mat[M+2][N+2];
		fr(i,0,M+2) {
			fr(j,0,N+2) {
				tmpnde.dist=INT_MAX;
				tmpnde.dang[0]=0,tmpnde.dang[1]=0,tmpnde.dang[2]=0,tmpnde.dang[3]=0;
				if(i==0 || i==M+1 || j==0 || j==N+1) {
					tmpnde.item='#';
				}
				else {
					//pf("-enter-");
					sc("%c",&tmpnde.item);
					//pf("q-%c-q",tmpnde.item);
				}
				if(tmpnde.item=='S') {
					st.first=i,st.second=j;
				}
				else if(tmpnde.item=='G') {
					en.first=i,en.second=j;
				}
				mat[i][j]=tmpnde;
			}
			if(!(i==0 || i==M+1 || j==0 || j==N+1)) {
				sc("%c",&ch);
			}
		}
		/*fr(i,0,M+2) {
			fr(j,0,N+2) {
				pf("%c ",mat[i][j].item);
			}
			pf("\n");
		}*/
		fr(i,1,M+1) {
			fr(j,1,N+1) {
				if(mat[i][j].item=='v') {
					fr(k,i+1,M+2) {
						if(mat[k][j].item=='.')
							mat[k][j].dang[0]=1;
						else if(mat[k][j].item=='S' || mat[k][j].item=='G') {
							mat[k][j].dang[0]=1;
							//while(k<M+2) {mat[k][j].dang[0]=mat[k][j].dang[0]||0;k++;}
						}
						else {
							while(k<M+2) {mat[k][j].dang[0]=mat[k][j].dang[0]||0;k++;}
						}
					}
					ifr(k,i-1,-1) {
						if(mat[k][j].item=='.')
							mat[k][j].dang[2]=1;
						else if(mat[k][j].item=='S' || mat[k][j].item=='G') {
							mat[k][j].dang[2]=1;
							//while(k>=0) {mat[k][j].dang[2]=mat[k][j].dang[2]||0;k--;}
						}
						else {
							while(k>=0) {mat[k][j].dang[2]=mat[k][j].dang[2]||0;k--;}
						}
					}
					fr(k,j+1,N+2) {
						if(mat[i][k].item=='.')
							mat[i][k].dang[3]=1;
						else if(mat[i][k].item=='S' || mat[i][k].item=='G') {
							mat[i][k].dang[3]=1;
							//while(k<N+2) {mat[i][k].dang[3]=mat[i][k].dang[3]||0;k++;}
						}
						else {
							while(k<N+2) {mat[i][k].dang[3]=mat[i][k].dang[3]||0;k++;}
						}
					}
					ifr(k,j-1,-1) {
						if(mat[i][k].item=='.')
							mat[i][k].dang[1]=1;
						else if(mat[i][k].item=='S' || mat[i][k].item=='G') {
							mat[i][k].dang[1]=1;
							//while(k>=0) {mat[i][k].dang[1]=mat[i][k].dang[1]||0;k--;}
						}
						else {
							while(k>=0) {mat[i][k].dang[1]=mat[i][k].dang[1]||0;k--;}
						}
					}
				}
				else if(mat[i][j].item=='<') {
					fr(k,i+1,M+2) {
						if(mat[k][j].item=='.')
							mat[k][j].dang[3]=1;
						else if(mat[k][j].item=='S' || mat[k][j].item=='G') {
							mat[k][j].dang[3]=1;
							//while(k<M+2) {mat[k][j].dang[3]=mat[k][j].dang[3]||0;k++;}
						}
						else {
							while(k<M+2) {mat[k][j].dang[3]=mat[k][j].dang[3]||0;k++;}
						}
					}
					ifr(k,i-1,-1) {
						if(mat[k][j].item=='.')
							mat[k][j].dang[1]=1;
						else if(mat[k][j].item=='S' || mat[k][j].item=='G') {
							mat[k][j].dang[1]=1;
							//while(k>=0) {mat[k][j].dang[1]=mat[k][j].dang[1]||0;k--;}
						}
						else {
							while(k>=0) {mat[k][j].dang[1]=mat[k][j].dang[1]||0;k--;}
						}
					}
					fr(k,j+1,N+2) {
						if(mat[i][k].item=='.')
							mat[i][k].dang[2]=1;
						else if(mat[i][k].item=='S' || mat[i][k].item=='G') {
							mat[i][k].dang[2]=1;
							//while(k<N+2) {mat[i][k].dang[2]=mat[i][k].dang[2]||0;k++;}
						}
						else {
							while(k<N+2) {mat[i][k].dang[2]=mat[i][k].dang[2]||0;k++;}
						}
					}
					ifr(k,j-1,-1) {
						if(mat[i][k].item=='.')
							mat[i][k].dang[0]=1;
						else if(mat[i][k].item=='S' || mat[i][k].item=='G') {
							mat[i][k].dang[0]=1;
							//while(k>=0) {mat[i][k].dang[0]=mat[i][k].dang[0]||0;k--;}
						}
						else {
							while(k>=0) {mat[i][k].dang[0]=mat[i][k].dang[0]||0;k--;}
						}
					}
				}
				else if(mat[i][j].item=='>') {
					fr(k,i+1,M+2) {
						if(mat[k][j].item=='.')
							mat[k][j].dang[1]=1;
						else if(mat[k][j].item=='S' || mat[k][j].item=='G') {
							mat[k][j].dang[1]=1;
							//while(k<M+2) {mat[k][j].dang[1]=mat[k][j].dang[1]||0;k++;}
						}
						else {
							while(k<M+2) {mat[k][j].dang[1]=mat[k][j].dang[1]||0;k++;}
						}
					}
					ifr(k,i-1,-1) {
						if(mat[k][j].item=='.')
							mat[k][j].dang[3]=1;
						else if(mat[k][j].item=='S' || mat[k][j].item=='G') {
							mat[k][j].dang[3]=1;
							//while(k>=0) {mat[k][j].dang[3]=mat[k][j].dang[3]||0;k--;}
						}
						else {
							while(k>=0) {mat[k][j].dang[3]=mat[k][j].dang[3]||0;k--;}
						}
					}
					fr(k,j+1,N+2) {
						if(mat[i][k].item=='.')
							mat[i][k].dang[0]=1;
						else if(mat[i][k].item=='S' || mat[i][k].item=='G') {
							mat[i][k].dang[0]=1;
							//while(k<N+2) {mat[i][k].dang[0]=mat[i][k].dang[0]||0;k++;}
						}
						else {
							while(k<N+2) {mat[i][k].dang[0]=mat[i][k].dang[0]||0;k++;}
						}
					}
					ifr(k,j-1,-1) {
						if(mat[i][k].item=='.')
							mat[i][k].dang[2]=1;
						else if(mat[i][k].item=='S' || mat[i][k].item=='G') {
							mat[i][k].dang[2]=1;
							//while(k>=0) {mat[i][k].dang[2]=mat[i][k].dang[2]||0;k--;}
						}
						else {
							while(k>=0) {mat[i][k].dang[2]=mat[i][k].dang[2]||0;k--;}
						}
					}
				}
				else if(mat[i][j].item=='^') {
					fr(k,i+1,M+2) {
						if(mat[k][j].item=='.')
							mat[k][j].dang[2]=1;
						else if(mat[k][j].item=='S' || mat[k][j].item=='G') {
							mat[k][j].dang[2]=1;
							//while(k<M+2) {mat[k][j].dang[2]=mat[k][j].dang[2]||0;k++;}
						}
						else {
							while(k<M+2) {mat[k][j].dang[2]=mat[k][j].dang[2]||0;k++;}
						}
					}
					ifr(k,i-1,-1) {
						if(mat[k][j].item=='.')
							mat[k][j].dang[0]=1;
						else if(mat[k][j].item=='S' || mat[k][j].item=='G') {
							mat[k][j].dang[0]=1;
							//while(k>=0) {mat[k][j].dang[0]=mat[k][j].dang[0]||0;k--;}
						}
						else {
							while(k>=0) {mat[k][j].dang[0]=mat[k][j].dang[0]||0;k--;}
						}
					}
					fr(k,j+1,N+2) {
						if(mat[i][k].item=='.')
							mat[i][k].dang[1]=1;
						else if(mat[i][k].item=='S' || mat[i][k].item=='G') {
							mat[i][k].dang[1]=1;
							//while(k<N+2) {mat[i][k].dang[1]=mat[i][k].dang[1]||0;k++;}
						}
						else {
							while(k<N+2) {mat[i][k].dang[1]=mat[i][k].dang[1]||0;k++;}
						}
					}
					ifr(k,j-1,-1) {
						if(mat[i][k].item=='.')
							mat[i][k].dang[3]=1;
						else if(mat[i][k].item=='S' || mat[i][k].item=='G') {
							mat[i][k].dang[3]=1;
							//while(k>=0) {mat[i][k].dang[3]=mat[i][k].dang[3]||0;k--;}
						}
						else {
							while(k>=0) {mat[i][k].dang[3]=mat[i][k].dang[3]||0;k--;}
						}
					}
				}
			}
		}
		/*fr(i,1,M+1) {
			fr(j,1,N+1) {
				pf("%d %d %d %d",mat[i][j].dang[0],mat[i][j].dang[1],mat[i][j].dang[2],mat[i][j].dang[3]);
			}
			pf("\n");
		}
		pf("\n");*/
		//dijikstra
		queue<pair<int,int> > Q;
		Q.push(make_pair(st.first,st.second));
		mat[st.first][st.second].dist=0;
		while(!Q.empty()) {
			ptmp1=Q.front();
			//pf("%d %d\n",ptmp1.first,ptmp1.second);
			Q.pop();
			ch=mat[ptmp1.first+1][ptmp1.second].item;
			if((ch=='.'||ch=='G') && mat[ptmp1.first+1][ptmp1.second].dang[(mat[ptmp1.first][ptmp1.second].dist+1)%4]==0 && mat[ptmp1.first+1][ptmp1.second].dist>mat[ptmp1.first][ptmp1.second].dist+1) {
				mat[ptmp1.first+1][ptmp1.second].dist=mat[ptmp1.first][ptmp1.second].dist+1;
				Q.push(make_pair(ptmp1.first+1,ptmp1.second));
			}
			ch=mat[ptmp1.first-1][ptmp1.second].item;
			if((ch=='.'||ch=='G') && mat[ptmp1.first-1][ptmp1.second].dang[(mat[ptmp1.first][ptmp1.second].dist+1)%4]==0 && mat[ptmp1.first-1][ptmp1.second].dist>mat[ptmp1.first][ptmp1.second].dist+1) {
				mat[ptmp1.first-1][ptmp1.second].dist=mat[ptmp1.first][ptmp1.second].dist+1;
				Q.push(make_pair(ptmp1.first-1,ptmp1.second));
			}
			ch=mat[ptmp1.first][ptmp1.second+1].item;
			if((ch=='.'||ch=='G') && mat[ptmp1.first][ptmp1.second+1].dang[(mat[ptmp1.first][ptmp1.second].dist+1)%4]==0 && mat[ptmp1.first][ptmp1.second+1].dist>mat[ptmp1.first][ptmp1.second].dist+1) {
				//pf(" enter ");
				mat[ptmp1.first][ptmp1.second+1].dist=mat[ptmp1.first][ptmp1.second].dist+1;
				Q.push(make_pair(ptmp1.first,ptmp1.second+1));
			}
			ch=mat[ptmp1.first][ptmp1.second-1].item;
			if((ch=='.'||ch=='G') && mat[ptmp1.first][ptmp1.second-1].dang[(mat[ptmp1.first][ptmp1.second].dist+1)%4]==0 && mat[ptmp1.first][ptmp1.second-1].dist>mat[ptmp1.first][ptmp1.second].dist+1) {
				mat[ptmp1.first][ptmp1.second-1].dist=mat[ptmp1.first][ptmp1.second].dist+1;
				Q.push(make_pair(ptmp1.first,ptmp1.second-1));
			}
			tmp=mat[ptmp1.first][ptmp1.second].dist;
			//pf("%d\n",tmp);
			if(((mat[ptmp1.first+1][ptmp1.second].dang[(tmp+1)%4]==0)&&(mat[ptmp1.first+1][ptmp1.second].item=='.'))||((mat[ptmp1.first+1][ptmp1.second].dang[(tmp+1)%4]==0)&&(mat[ptmp1.first+1][ptmp1.second].item=='S'))||((mat[ptmp1.first+1][ptmp1.second].dang[(tmp+1)%4]==0)&&(mat[ptmp1.first+1][ptmp1.second].item=='G'))||((mat[ptmp1.first-1][ptmp1.second].dang[(tmp+1)%4]==0)&&(mat[ptmp1.first-1][ptmp1.second].item=='.'))||((mat[ptmp1.first-1][ptmp1.second].dang[(tmp+1)%4]==0)&&(mat[ptmp1.first-1][ptmp1.second].item=='S'))||((mat[ptmp1.first-1][ptmp1.second].dang[(tmp+1)%4]==0)&&(mat[ptmp1.first-1][ptmp1.second].item=='G'))||((mat[ptmp1.first][ptmp1.second+1].dang[(tmp+1)%4]==0)&&(mat[ptmp1.first][ptmp1.second+1].item=='.'))||((mat[ptmp1.first][ptmp1.second+1].dang[(tmp+1)%4]==0)&&(mat[ptmp1.first][ptmp1.second+1].item=='S'))||((mat[ptmp1.first][ptmp1.second+1].dang[(tmp+1)%4]==0)&&(mat[ptmp1.first][ptmp1.second+1].item=='G'))||((mat[ptmp1.first][ptmp1.second-1].dang[(tmp+1)%4]==0)&&(mat[ptmp1.first][ptmp1.second-1].item=='.'))||((mat[ptmp1.first][ptmp1.second-1].dang[(tmp+1)%4]==0)&&(mat[ptmp1.first][ptmp1.second-1].item=='S'))||((mat[ptmp1.first][ptmp1.second-1].dang[(tmp+1)%4]==0)&&(mat[ptmp1.first][ptmp1.second-1].item=='G'))) {
				ch=mat[ptmp1.first+1][ptmp1.second].item;
				//pf("%d %d %d %c\n",ptmp1.first,ptmp1.second,mat[ptmp1.first][ptmp1.second].dist,mat[ptmp1.first][ptmp1.second].item);
				//pf("qq%d %cqq",mat[ptmp1.first][ptmp1.second-1].dang[tmp+1]%4,mat[ptmp1.first][ptmp1.second-1].item);
				if((ch=='.'||ch=='G') && mat[ptmp1.first+1][ptmp1.second].dang[(mat[ptmp1.first][ptmp1.second].dist+1)%4]==1 && mat[ptmp1.first+1][ptmp1.second].dang[(mat[ptmp1.first][ptmp1.second].dist+3)%4]!=1 && mat[ptmp1.first+1][ptmp1.second].dist>mat[ptmp1.first][ptmp1.second].dist+3) {
					//jump cond
					mat[ptmp1.first+1][ptmp1.second].dist=mat[ptmp1.first][ptmp1.second].dist+3;
					Q.push(make_pair(ptmp1.first+1,ptmp1.second));
				}
				ch=mat[ptmp1.first-1][ptmp1.second].item;
				if((ch=='.'||ch=='G') && mat[ptmp1.first-1][ptmp1.second].dang[(mat[ptmp1.first][ptmp1.second].dist+1)%4]==1 && mat[ptmp1.first-1][ptmp1.second].dang[(mat[ptmp1.first][ptmp1.second].dist+3)%4]!=1 && mat[ptmp1.first-1][ptmp1.second].dist>mat[ptmp1.first][ptmp1.second].dist+3) {
					//jump cond
					mat[ptmp1.first-1][ptmp1.second].dist=mat[ptmp1.first][ptmp1.second].dist+3;
					Q.push(make_pair(ptmp1.first-1,ptmp1.second));
				}
				ch=mat[ptmp1.first][ptmp1.second+1].item;
				if((ch=='.'||ch=='G') && mat[ptmp1.first][ptmp1.second+1].dang[(mat[ptmp1.first][ptmp1.second].dist+1)%4]==1 && mat[ptmp1.first][ptmp1.second+1].dang[(mat[ptmp1.first][ptmp1.second].dist+3)%4]!=1 && mat[ptmp1.first][ptmp1.second+1].dist>mat[ptmp1.first][ptmp1.second].dist+3) {
					//jump cond
					mat[ptmp1.first][ptmp1.second+1].dist=mat[ptmp1.first][ptmp1.second].dist+3;
					Q.push(make_pair(ptmp1.first,ptmp1.second+1));
				}
				ch=mat[ptmp1.first][ptmp1.second-1].item;
				if((ch=='.'||ch=='G') && mat[ptmp1.first][ptmp1.second-1].dang[(mat[ptmp1.first][ptmp1.second].dist+1)%4]==1 && mat[ptmp1.first][ptmp1.second-1].dang[(mat[ptmp1.first][ptmp1.second].dist+3)%4]!=1 && mat[ptmp1.first][ptmp1.second-1].dist>mat[ptmp1.first][ptmp1.second].dist+3) {
					//jump cond
					mat[ptmp1.first][ptmp1.second-1].dist=mat[ptmp1.first][ptmp1.second].dist+3;
					Q.push(make_pair(ptmp1.first,ptmp1.second-1));
				}
			}
		}
		//pf("%-d %d-",en.first,en.second);
		/*fr(i,1,M+1) {
			fr(j,1,N+1) {
				if(mat[i][j].dist==INT_MAX)
					pf("-1");
				else
					pf("%d",mat[i][j].dist);
			}
			pf("\n");
		}*/
		if(mat[en.first][en.second].dist!=INT_MAX)
			pf("Case #%d: %d\n",tmp4,mat[en.first][en.second].dist);
		else
			pf("Case #%d: impossible\n",tmp4);
	}
	return 0;
}