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
#define fr(i,m,n) for(i=m;i<n;i++)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1,tmp2,tmp3,tmp=0
using namespace std;
int arr[101][101]={0};
void print(int W,int H) {
	var(int);
	fr(i,0,H) {
		fr(j,0,W) {
			arr[i][j]==0?pf("."):pf("x");
			//pf("%d",arr[i][j]);
		}
		pf("\n");
	}
}
int form_block(int t,int r,int x,int H,int W) {
	var(int);
	//pf("%d %d\n",t,r);
	if((t==1)&&(r==0)) {
		int block[4][4]={{2,0,0,0},
						 {2,2,0,0},
						 {0,2,0,0},
						 {0,0,0,0}};
		fr(i,0,4) {
			fr(j,0,4) {
				if((arr[i][x+j]==1)&&(block[i][j]==2)) {
					pf("Game Over!\n");
					return 0;
				}
				else if(block[i][j]==2 && (i>=H || j>=W)) {
					pf("Game Over!\n");
					return 0;
				}
				arr[i][x+j]=block[i][j];
			}
		}
	}
	else if((t==1)&&(r==1)) {
		int block[4][4]={{0,2,2,0},
						 {2,2,0,0},
						 {0,0,0,0},
						 {0,0,0,0}};
						 		fr(i,0,4) {
			fr(j,0,4) {
				if((arr[i][x+j]==1)&&(block[i][j]==2)) {
					pf("Game Over!\n");
					return 0;
				}
				else if(block[i][j]==2 && (i>=H || j>=W)) {
					pf("Game Over!\n");
					return 0;
				}
				arr[i][x+j]=block[i][j];
			}
		}
 	}
	else if((t==1)&&(r==2)) {
		int block[4][4]={{2,0,0,0},
						 {2,2,0,0},
						 {0,2,0,0},
						 {0,0,0,0}};
						 		fr(i,0,4) {
			fr(j,0,4) {
				if((arr[i][x+j]==1)&&(block[i][j]==2)) {
					pf("Game Over!\n");
					return 0;
				}
				else if(block[i][j]==2 && (i>=H || j>=W)) {
					pf("Game Over!\n");
					return 0;
				}
				arr[i][x+j]=block[i][j];
			}
		}
	}
	else if((t==1)&&(r==3)) {
		int block[4][4]={{0,2,2,0},
						 {2,2,0,0},
						 {0,0,0,0},
						 {0,0,0,0}};
						 		fr(i,0,4) {
			fr(j,0,4) {
				if((arr[i][x+j]==1)&&(block[i][j]==2)) {
					pf("Game Over!\n");
					return 0;
				}
				else if(block[i][j]==2 && (i>=H || j>=W)) {
					pf("Game Over!\n");
					return 0;
				}
				arr[i][x+j]=block[i][j];
			}
		}
	}
	else if((t==2)&&((r==0)||(r==2))) {
		int block[4][4]={{0,2,0,0},
						 {2,2,0,0},
						 {2,0,0,0},
						 {0,0,0,0}};
						 		fr(i,0,4) {
			fr(j,0,4) {
				if((arr[i][x+j]==1)&&(block[i][j]==2)) {
					pf("Game Over!\n");
					return 0;
				}
				else if(block[i][j]==2 && (i>=H || j>=W)) {
					pf("Game Over!\n");
					return 0;
				}
				arr[i][x+j]=block[i][j];
			}
		}
	}
	else if((t==2)&&((r==1)||(r==3))) {
		int block[4][4]={{2,2,0,0},
						 {0,2,2,0},
						 {0,0,0,0},
						 {0,0,0,0}};
			fr(i,0,4) {
			fr(j,0,4) {
				if((arr[i][x+j]==1)&&(block[i][j]==2)) {
					pf("Game Over!\n");
					return 0;
				}
				else if(block[i][j]==2 && (i>=H || j>=W)) {
					pf("Game Over!\n");
					return 0;
				}
				arr[i][x+j]=block[i][j];
			}
		}
	}
	else if((t==3)&&(r==0)) {
		int block[4][4]={{2,0,0,0},
						 {2,0,0,0},
						 {2,2,0,0},
						 {0,0,0,0}};
						 		fr(i,0,4) {
			fr(j,0,4) {
				if((arr[i][x+j]==1)&&(block[i][j]==2)) {
					pf("Game Over!\n");
					return 0;
				}
				else if(block[i][j]==2 && (i>=H || j>=W)) {
					pf("Game Over!\n");
					return 0;
				}
				arr[i][x+j]=block[i][j];
			}
		}
	}
	else if((t==3)&&(r==1)) {
		int block[4][4]={{0,0,2,0},
						 {2,2,2,0},
						 {0,0,0,0},
						 {0,0,0,0}};
						 		fr(i,0,4) {
			fr(j,0,4) {
				if((arr[i][x+j]==1)&&(block[i][j]==2)) {
					pf("Game Over!\n");
					return 0;
				}
				else if(block[i][j]==2 && (i>=H || j>=W)) {
					pf("Game Over!\n");
					return 0;
				}
				arr[i][x+j]=block[i][j];
			}
		}
	}
	else if((t==3)&&(r==2)) {
		int block[4][4]={{2,2,0,0},
						 {0,2,0,0},
						 {0,2,0,0},
						 {0,0,0,0}};
						 		fr(i,0,4) {
			fr(j,0,4) {
				if((arr[i][x+j]==1)&&(block[i][j]==2)) {
					pf("Game Over!\n");
					return 0;
				}
				else if(block[i][j]==2 && (i>=H || j>=W)) {
					pf("Game Over!\n");
					return 0;
				}
				arr[i][x+j]=block[i][j];
			}
		}
	}
	else if((t==3)&&(r==3)) {
		int block[4][4]={{2,2,2,0},
						 {2,0,0,0},
						 {0,0,0,0},
						 {0,0,0,0}};
						 		fr(i,0,4) {
			fr(j,0,4) {
				if((arr[i][x+j]==1)&&(block[i][j]==2)) {
					pf("Game Over!\n");
					return 0;
				}
				else if(block[i][j]==2 && (i>=H || j>=W)) {
					pf("Game Over!\n");
					return 0;
				}
				arr[i][x+j]=block[i][j];
			}
		}
	}
	else if((t==4)&&(r==0)) {
		int block[4][4]={{0,2,0,0},
						 {0,2,0,0},
						 {2,2,0,0},
						 {0,0,0,0}};
						 		fr(i,0,4) {
			fr(j,0,4) {
				if((arr[i][x+j]==1)&&(block[i][j]==2)) {
					pf("Game Over!\n");
					return 0;
				}
				else if(block[i][j]==2 && (i>=H || j>=W)) {
					pf("Game Over!\n");
					return 0;
				}
				arr[i][x+j]=block[i][j];
			}
		}
	}
	else if((t==4)&&(r==1)) {
		int block[4][4]={{2,2,2,0},
						 {0,0,2,0},
						 {0,0,0,0},
						 {0,0,0,0}};
						 		fr(i,0,4) {
			fr(j,0,4) {
				if((arr[i][x+j]==1)&&(block[i][j]==2)) {
					pf("Game Over!\n");
					return 0;
				}
				else if(block[i][j]==2 && (i>=H || j>=W)) {
					pf("Game Over!\n");
					return 0;
				}
				arr[i][x+j]=block[i][j];
			}
		}
	}
	else if((t==4)&&(r==2)) {
		int block[4][4]={{2,2,0,0},
						 {2,0,0,0},
						 {2,0,0,0},
						 {0,0,0,0}};
						 		fr(i,0,4) {
			fr(j,0,4) {
				if((arr[i][x+j]==1)&&(block[i][j]==2)) {
					pf("Game Over!\n");
					return 0;
				}
				else if(block[i][j]==2 && (i>=H || j>=W)) {
					pf("Game Over!\n");
					return 0;
				}
				arr[i][x+j]=block[i][j];
			}
		}
	}
	else if((t==4)&&(r==3)) {
		int block[4][4]={{2,0,0,0},
						 {2,2,2,0},
						 {0,0,0,0},
						 {0,0,0,0}};
						 		fr(i,0,4) {
			fr(j,0,4) {
				if((arr[i][x+j]==1)&&(block[i][j]==2)) {
					pf("Game Over!\n");
					return 0;
				}
				else if(block[i][j]==2 && (i>=H || j>=W)) {
					pf("Game Over!\n");
					return 0;
				}
				arr[i][x+j]=block[i][j];
			}
		}
	}
	else if((t==5)) {
		int block[4][4]={{2,2,0,0},
						 {2,2,0,0},
						 {0,0,0,0},
						 {0,0,0,0}};		
						 		fr(i,0,4) {
			fr(j,0,4) {
				if((arr[i][x+j]==1)&&(block[i][j]==2)) {
					pf("Game Over!\n");
					return 0;
				}
				else if(block[i][j]==2 && (i>=H || j>=W)) {
					pf("Game Over!\n");
					return 0;
				}
				arr[i][x+j]=block[i][j];
			}
		}
	}
	else if((t==6)&&((r==0)||(r==2))) {
		int block[4][4]={{2,0,0,0},
						 {2,0,0,0},
						 {2,0,0,0},
						 {2,0,0,0}};
						 		fr(i,0,4) {
			fr(j,0,4) {
				if((arr[i][x+j]==1)&&(block[i][j]==2)) {
					pf("Game Over!\n");
					return 0;
				}
				else if(block[i][j]==2 && (i>=H || j>=W)) {
					pf("Game Over!\n");
					return 0;
				}
				arr[i][x+j]=block[i][j];
			}
		}
	}
	else if((t==6)&&((r==1)||(r==3))) {
		int block[4][4]={{2,2,2,2},
						 {0,0,0,0},
						 {0,0,0,0},
						 {0,0,0,0}};
						 		fr(i,0,4) {
			fr(j,0,4) {
				if((arr[i][x+j]==1)&&(block[i][j]==2)) {
					pf("Game Over!\n");
					return 0;
				}
				else if(block[i][j]==2 && (i>=H || j>=W)) {
					pf("Game Over!\n");
					return 0;
				}
				arr[i][x+j]=block[i][j];
			}
		}
	}
	else if((t==7)&&(r==0)) {
		int block[4][4]={{0,2,0,0},
						 {2,2,2,0},
						 {0,0,0,0},
						 {0,0,0,0}};
						 		fr(i,0,4) {
			fr(j,0,4) {
				if((arr[i][x+j]==1)&&(block[i][j]==2)) {
					pf("Game Over!\n");
					return 0;
				}
				else if(block[i][j]==2 && (i>=H || j>=W)) {
					pf("Game Over!\n");
					return 0;
				}
				arr[i][x+j]=block[i][j];
			}
		}
	}
	else if((t==7)&&(r==1)) {
		int block[4][4]={{0,2,0,0},
						 {2,2,0,0},
						 {0,2,0,0},
						 {0,0,0,0}};
						 		fr(i,0,4) {
			fr(j,0,4) {
				if((arr[i][x+j]==1)&&(block[i][j]==2)) {
					pf("Game Over!\n");
					return 0;
				}
				else if(block[i][j]==2 && (i>=H || j>=W)) {
					pf("Game Over!\n");
					return 0;
				}
				arr[i][x+j]=block[i][j];
			}
		}
	}
	else if((t==7)&&(r==2)) {
		int block[4][4]={{2,2,2,0},
						 {0,2,0,0},
						 {0,0,0,0},
						 {0,0,0,0}};
						 		fr(i,0,4) {
			fr(j,0,4) {
				if((arr[i][x+j]==1)&&(block[i][j]==2)) {
					pf("Game Over!\n");
					return 0;
				}
				else if(block[i][j]==2 && (i>=H || j>=W)) {
					pf("Game Over!\n");
					return 0;
				}
				arr[i][x+j]=block[i][j];
			}
		}
	}
	else if((t==7)&&(r==3)) {
		int block[4][4]={{2,0,0,0},
						 {2,2,0,0},
						 {2,0,0,0},
						 {0,0,0,0}};
						 		fr(i,0,4) {
			fr(j,0,4) {
				if((arr[i][x+j]==1)&&(block[i][j]==2)) {
					pf("Game Over!\n");
					return 0;
				}
				else if(block[i][j]==2 && (i>=H || j>=W)) {
					pf("Game Over!\n");
					return 0;
				}
				arr[i][x+j]=block[i][j];
			}
		}
	}
	return 1;
}
void init() {
	var(int);
	fr(i,0,101)
		fr(j,0,101)
			arr[i][j]=0;
}
int main() {
	var(int);
	int T,W,H,N,t,r,x,ii;
	sc("%d",&T);
	int flag;
	fr(ii,1,T+1) {
		//pf("%d %d",i,T+1);
		init();
		flag=0;
		sc("%d %d %d",&W,&H,&N);
		pf("Case #%d:\n",ii);
		while(N--) {
			//pf("n");
			sc("%d %d %d",&t,&r,&x);
			//pf("%d\n",form_block(t,r,x));
			if(form_block(t,r,x,H,W)==0) {
				flag=1;
				break;
			}
			//simulate
			fr(i,0,H) {
				tmp1=0;
				fr(j,0,W) {
					if(arr[i][j]==2) {
						tmp1=1;
						break;
					}
				}
				if(tmp1==0)
					break;
			}
			//pf("\n%d\n",i);
			while(i<H) {
				//pf("\n newline \n");
				tmp1=0;
				fr(k,0,W) {
					if((arr[i][k]==1)&&(arr[i-1][k]==2)) {
						tmp1=1;
						break;
					}
				}
				if(tmp1==1)
					break;
				fr(k,0,W) {
					if(arr[i-1][k]==2) {
						arr[i][k]=2;
						arr[i-1][k]=0;
					}
				}
				//print(W,H);
				//pf("\n");
				fr(k,0,W) {
					if(i-2<0)
						continue;
					if(arr[i-2][k]==2) {
						arr[i-1][k]=2;
						arr[i-2][k]=0;
					}
				}
				//print(W,H);
				//pf("\n");
				fr(k,0,W) {
					if(i-3<0)
						continue;
					if(arr[i-3][k]==2) {
						arr[i-2][k]=2;
						arr[i-3][k]=0;
					}
				}
				//print(W,H);
				//pf("\n");
				fr(k,0,W) {
					if(i-4<0)
						continue;
					if(arr[i-4][k]==2) {
						arr[i-3][k]=2;
						arr[i-4][k]=0;
					}
				}
				//pf("\n%d ",i);
				//print(W,H);
				//pf("\n");
				i++;
			}
			//pf("\n");
			//print(W,H);
			//pf("\n");
			//merge
			fr(i,0,H)
				fr(j,0,W)
					arr[i][j]=(arr[i][j]==2?1:arr[i][j]);
			//line cancel
			for(i=H-1;i>=0;i--) {
				tmp1=0;
				fr(j,0,W) {
					if(arr[i][j]==0)
						tmp1=1;
				}
				if(tmp1==0) {
					//pf("cancel line %d\n",i);
					//cancel the line i
					for(tmp2=i;tmp2>=1;tmp2--) {
						fr(tmp3,0,W) {
							arr[tmp2][tmp3]=arr[tmp2-1][tmp3];
						}
					}
					i++;
				}
			}
		}
		if(flag==1)
			while(N--)
				sc("%d %d %d",&t,&r,&x);
		else
			print(W,H);
	}
	return 0;
}
