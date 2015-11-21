#include<bits/stdc++.h>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1=0,tmp2=0,tmp3=0,tmp=0,tmp4=0,tmp5=0,flag=0,T=0,N=0,Q=0
#define pb push_back
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
using namespace std;

int game[20][20];

bool checkGameOver() {
	var(int);
	fr(i,1,16) {
		if(game[0][i]==1) return true;
	}
	return false;
}

bool possibleFit(int i, int j, int type, char rot) {
	// check weather i,j has possible fit for type and rot
	if(type==1) {
		if(rot=='a') {
			int k;
			fr(k,0,4) if(game[i][j+k]) return false;
			return true;
		}
		else {
			int k;
			fr(k,0,4) if(game[i+k][j]) return false;
		}
	}
	else if(type==2) {
		if(rot=='a') {
			
		}
		else if(rot=='b') {
			
		}
		else if(rot=='c') {
			
		}
		else if(rot=='d') {
			
		}
	}
	else if(type==3) {
		if(rot=='a') {
			
		}
		else if(rot=='b') {
			
		}
		else if(rot=='c') {
			
		}
		else if(rot=='d') {
			
		}
	}
	else if(type==4) {
		// rot='a'
	}
	else if(type==5) {
		if(rot=='a') {
			
		}
		else if(rot=='b') {
			
		}
	}
	else if(type==6) {
		if(rot=='a') {
			
		}
		else if(rot=='b') {
			
		}
		else if(rot=='c') {
			
		}
		else if(rot=='d') {
			
		}
	}
	else if(type==7) {
		if(rot=='a') {
			
		}
		else if(rot=='b') {
			
		}
	}
}

int getNbr(int i,int j, int type, char rot) {
	// get the numner of neighbours attach with this fit

}

void getOutput(int &i,int &j,int type,char rot) {
	// get the real value of i and j to be printed on output
	// this value will be (i=bottom most and j=left most)

}

pair<char,pair<int,int> >getPosition(int type, char rot='x') {
	var(int);
	int bestI,bestJ,tmpI,tmpJ,maxNbr=0,tmpNbr;
	char gRot;
	if(type==1) {
		if(rot=='x') {
			// can select rotation as well
			rot='a';
			fr(i,1,16) {
				fr(j,1,16) {
					if(possibleFit(i,j,type,rot)) {
						tmpNbr=getNbr(i,j,type,rot);
						if(tmpNbr>maxNbr) {
							maxNbr=tmpNbr;
							bestI=tmpI;
							bestJ=tmpJ;
							gRot=rot;
						}
					}
				}
			}
			rot='b';
			fr(i,1,16) {
				fr(j,1,16) {
					if(possibleFit(i,j,type,rot)) {
						tmpNbr=getNbr(i,j,type,rot);
						if(tmpNbr>maxNbr) {
							maxNbr=tmpNbr;
							bestI=tmpI;
							bestJ=tmpJ;
							gRot=rot;
						}
					}
				}
			}
		}
		else {
			// can only select position
			gRot=rot;
			fr(i,1,16) {
				fr(j,1,16) {
					if(possibleFit(i,j,type,rot)) {
						tmpNbr=getNbr(i,j,type,rot);
						if(tmpNbr>maxNbr) {
							maxNbr=tmpNbr;
							bestI=tmpI;
							bestJ=tmpJ;
						}
					}
				}
			}
		}
		getOutput(i,j,type,gRot);
	}
	else if(type==2) {
		if(rot=='x') {
			// can select rotation as well
			rot='a';
			fr(i,1,16) {
				fr(j,1,16) {
					if(possibleFit(i,j,type,rot)) {
						tmpNbr=getNbr(i,j,type,rot);
						if(tmpNbr>maxNbr) {
							maxNbr=tmpNbr;
							bestI=tmpI;
							bestJ=tmpJ;
							gRot=rot;
						}
					}
				}
			}
			rot='b';
			fr(i,1,16) {
				fr(j,1,16) {
					if(possibleFit(i,j,type,rot)) {
						tmpNbr=getNbr(i,j,type,rot);
						if(tmpNbr>maxNbr) {
							maxNbr=tmpNbr;
							bestI=tmpI;
							bestJ=tmpJ;
							gRot=rot;
						}
					}
				}
			}
			rot='c';
			fr(i,1,16) {
				fr(j,1,16) {
					if(possibleFit(i,j,type,rot)) {
						tmpNbr=getNbr(i,j,type,rot);
						if(tmpNbr>maxNbr) {
							maxNbr=tmpNbr;
							bestI=tmpI;
							bestJ=tmpJ;
							gRot=rot;
						}
					}
				}
			}
			rot='d';
			fr(i,1,16) {
				fr(j,1,16) {
					if(possibleFit(i,j,type,rot)) {
						tmpNbr=getNbr(i,j,type,rot);
						if(tmpNbr>maxNbr) {
							maxNbr=tmpNbr;
							bestI=tmpI;
							bestJ=tmpJ;
							gRot=rot;
						}
					}
				}
			}
		}
		else {
			// can only select position
			gRot=rot;
			fr(i,1,16) {
				fr(j,1,16) {
					if(possibleFit(i,j,type,rot)) {
						tmpNbr=getNbr(i,j,type,rot);
						if(tmpNbr>maxNbr) {
							maxNbr=tmpNbr;
							bestI=tmpI;
							bestJ=tmpJ;
						}
					}
				}
			}
		}
		getOutput(i,j,type,gRot);
	}
	else if(type==3) {
		if(rot=='x') {
			// can select rotation as well
			rot='a';
			fr(i,1,16) {
				fr(j,1,16) {
					if(possibleFit(i,j,type,rot)) {
						tmpNbr=getNbr(i,j,type,rot);
						if(tmpNbr>maxNbr) {
							maxNbr=tmpNbr;
							bestI=tmpI;
							bestJ=tmpJ;
							gRot=rot;
						}
					}
				}
			}
			rot='b';
			fr(i,1,16) {
				fr(j,1,16) {
					if(possibleFit(i,j,type,rot)) {
						tmpNbr=getNbr(i,j,type,rot);
						if(tmpNbr>maxNbr) {
							maxNbr=tmpNbr;
							bestI=tmpI;
							bestJ=tmpJ;
							gRot=rot;
						}
					}
				}
			}
			rot='c';
			fr(i,1,16) {
				fr(j,1,16) {
					if(possibleFit(i,j,type,rot)) {
						tmpNbr=getNbr(i,j,type,rot);
						if(tmpNbr>maxNbr) {
							maxNbr=tmpNbr;
							bestI=tmpI;
							bestJ=tmpJ;
							gRot=rot;
						}
					}
				}
			}
			rot='d';
			fr(i,1,16) {
				fr(j,1,16) {
					if(possibleFit(i,j,type,rot)) {
						tmpNbr=getNbr(i,j,type,rot);
						if(tmpNbr>maxNbr) {
							maxNbr=tmpNbr;
							bestI=tmpI;
							bestJ=tmpJ;
							gRot=rot;
						}
					}
				}
			}
		}
		else {
			// can only select position
			gRot=rot;
			fr(i,1,16) {
				fr(j,1,16) {
					if(possibleFit(i,j,type,rot)) {
						tmpNbr=getNbr(i,j,type,rot);
						if(tmpNbr>maxNbr) {
							maxNbr=tmpNbr;
							bestI=tmpI;
							bestJ=tmpJ;
						}
					}
				}
			}
		}
		getOutput(i,j,type,gRot);		
	}
	else if(type==4) {
		if(rot=='x') {
			// can select rotation as well
			rot='a';
			fr(i,1,16) {
				fr(j,1,16) {
					if(possibleFit(i,j,type,rot)) {
						tmpNbr=getNbr(i,j,type,rot);
						if(tmpNbr>maxNbr) {
							maxNbr=tmpNbr;
							bestI=tmpI;
							bestJ=tmpJ;
							gRot=rot;
						}
					}
				}
			}
		}
		else {
			// can only select position
			gRot=rot;
			fr(i,1,16) {
				fr(j,1,16) {
					if(possibleFit(i,j,type,rot)) {
						tmpNbr=getNbr(i,j,type,rot);
						if(tmpNbr>maxNbr) {
							maxNbr=tmpNbr;
							bestI=tmpI;
							bestJ=tmpJ;
						}
					}
				}
			}
		}
		getOutput(i,j,type,gRot);
	}
	else if(type==5) {
		if(rot=='x') {
			// can select rotation as well
			rot='a';
			fr(i,1,16) {
				fr(j,1,16) {
					if(possibleFit(i,j,type,rot)) {
						tmpNbr=getNbr(i,j,type,rot);
						if(tmpNbr>maxNbr) {
							maxNbr=tmpNbr;
							bestI=tmpI;
							bestJ=tmpJ;
							gRot=rot;
						}
					}
				}
			}
			rot='b';
			fr(i,1,16) {
				fr(j,1,16) {
					if(possibleFit(i,j,type,rot)) {
						tmpNbr=getNbr(i,j,type,rot);
						if(tmpNbr>maxNbr) {
							maxNbr=tmpNbr;
							bestI=tmpI;
							bestJ=tmpJ;
							gRot=rot;
						}
					}
				}
			}
		}
		else {
			// can only select position
			gRot=rot;
			fr(i,1,16) {
				fr(j,1,16) {
					if(possibleFit(i,j,type,rot)) {
						tmpNbr=getNbr(i,j,type,rot);
						if(tmpNbr>maxNbr) {
							maxNbr=tmpNbr;
							bestI=tmpI;
							bestJ=tmpJ;
						}
					}
				}
			}
		}
		getOutput(i,j,type,gRot);		
	}
	else if(type==6) {
		if(rot=='x') {
			// can select rotation as well
			rot='a';
			fr(i,1,16) {
				fr(j,1,16) {
					if(possibleFit(i,j,type,rot)) {
						tmpNbr=getNbr(i,j,type,rot);
						if(tmpNbr>maxNbr) {
							maxNbr=tmpNbr;
							bestI=tmpI;
							bestJ=tmpJ;
							gRot=rot;
						}
					}
				}
			}
			rot='b';
			fr(i,1,16) {
				fr(j,1,16) {
					if(possibleFit(i,j,type,rot)) {
						tmpNbr=getNbr(i,j,type,rot);
						if(tmpNbr>maxNbr) {
							maxNbr=tmpNbr;
							bestI=tmpI;
							bestJ=tmpJ;
							gRot=rot;
						}
					}
				}
			}
			rot='c';
			fr(i,1,16) {
				fr(j,1,16) {
					if(possibleFit(i,j,type,rot)) {
						tmpNbr=getNbr(i,j,type,rot);
						if(tmpNbr>maxNbr) {
							maxNbr=tmpNbr;
							bestI=tmpI;
							bestJ=tmpJ;
							gRot=rot;
						}
					}
				}
			}
			rot='d';
			fr(i,1,16) {
				fr(j,1,16) {
					if(possibleFit(i,j,type,rot)) {
						tmpNbr=getNbr(i,j,type,rot);
						if(tmpNbr>maxNbr) {
							maxNbr=tmpNbr;
							bestI=tmpI;
							bestJ=tmpJ;
							gRot=rot;
						}
					}
				}
			}
		}
		else {
			// can only select position
			gRot=rot;
			fr(i,1,16) {
				fr(j,1,16) {
					if(possibleFit(i,j,type,rot)) {
						tmpNbr=getNbr(i,j,type,rot);
						if(tmpNbr>maxNbr) {
							maxNbr=tmpNbr;
							bestI=tmpI;
							bestJ=tmpJ;
						}
					}
				}
			}
		}
		getOutput(i,j,type,gRot);		
	}
	else if(type==7) {
		if(rot=='x') {
			// can select rotation as well
			rot='a';
			fr(i,1,16) {
				fr(j,1,16) {
					if(possibleFit(i,j,type,rot)) {
						tmpNbr=getNbr(i,j,type,rot);
						if(tmpNbr>maxNbr) {
							maxNbr=tmpNbr;
							bestI=tmpI;
							bestJ=tmpJ;
							gRot=rot;
						}
					}
				}
			}
			rot='b';
			fr(i,1,16) {
				fr(j,1,16) {
					if(possibleFit(i,j,type,rot)) {
						tmpNbr=getNbr(i,j,type,rot);
						if(tmpNbr>maxNbr) {
							maxNbr=tmpNbr;
							bestI=tmpI;
							bestJ=tmpJ;
							gRot=rot;
						}
					}
				}
			}
		}
		else {
			// can only select position
			gRot=rot;
			fr(i,1,16) {
				fr(j,1,16) {
					if(possibleFit(i,j,type,rot)) {
						tmpNbr=getNbr(i,j,type,rot);
						if(tmpNbr>maxNbr) {
							maxNbr=tmpNbr;
							bestI=tmpI;
							bestJ=tmpJ;
						}
					}
				}
			}
		}
		getOutput(i,j,type,gRot);
	}
	return make_pair(gRot,make_pair(i,j));
}

void printGame() {
	var(int);
	fr(i,0,20) {
		fr(j,0,20) {
			pf("%d",game[i][j]);
		}
		pf("\n");
	}
}

int main() {
	var(int);
	int type,tetro,gameover=0;
	char ret;
	string str;
	// init game
	fr(i,0,20) {
		fr(j,0,20) {
			if(j<1 || j>15) game[i][j]=1;
			else if(i>15) game[i][j]=1;
			else game[i][j]=0;
		}
	}
	while(1) {
		printGame();
		pf("\n");
		if(gameover==1) {
			cin>>str;
			assert(str=="Game over");
			return 0;
		}
		sc("%d",&type);
		if(type==1) {
			sc("%d",&tetro);
			// get position and rotation. print (rotation,r,c)
		}
		else {
			sc("%d %c\n",&tetro,&ret);
			// get position and print (rotation,r,c)
		}

		fflush(stdout);
		// check cancellation
		// check gameover
		if(checkGameOver()) gameover=1;
	}
	return 0;
}