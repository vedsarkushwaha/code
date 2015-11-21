#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

typedef vector<int> vi;
typedef pair <int,int> ii;
typedef vector< vi > vvi;
typedef vector< ii > vii;
typedef vector< vii> vvii;

typedef struct {
	char type;
	int x;
	int y;
} guti;


bool check(guti f, guti s, int grid[10][10] ){


	if(f.type == 'K'){
		if( abs(f.y - s.y) <= 1  && abs(f.x - s.x) <= 1){
			return true;
		}
		else
			return false;
	}
	else if(f.type == 'Q'){
		//cout << "queen";
		int i,j;

		int k = s.x;
		int l = s.y;

		i = f.x + 1;
		j = f.y + 1;
		while(1){
			if(i == s.x && j== s.y)
				return true;

			if(grid[i][j] == 1)
				break;
			i++;
			j++;
		}

		i = f.x - 1;
		j = f.y + 1;
		while(1){
			if(i == s.x && j== s.y)
				return true;

			if(grid[i][j] == 1)
				break;
			i--;
			j++;
		}

		i = f.x + 1;
		j = f.y - 1;
		while(1){
			if(i == s.x && j== s.y)
				return true;

			if(grid[i][j] == 1)
				break;
			i++;
			j--;
		}

		i = f.x - 1;
		j = f.y - 1;
		while(1){
			//cout << "ghusa";
			if(i == s.x && j== s.y)
				return true;

			if(grid[i][j] == 1)
				break;
			i--;
			j--;
		}

		i = f.x + 1;
		j = f.y;
		while(1){
			if(i == s.x && j== s.y)
				return true;

			if(grid[i][j] == 1)
				break;
			i++;
			//j++;
		}

		i = f.x - 1;
		j = f.y;
		while(1){
			if(i == s.x && j== s.y)
				return true;

			if(grid[i][j] == 1)
				break;
			i--;
			//j++;
		}

		i = f.x;
		j = f.y - 1;
		while(1){
			if(i == s.x && j== s.y)
				return true;

			if(grid[i][j] == 1)
				break;
			//i++;
			j--;
		}

		i = f.x ;
		j = f.y + 1;
		while(1){
			if(i == s.x && j== s.y)
				return true;

			if(grid[i][j] == 1)
				break;
			j++;
		}

		return false;
	}
	else if(f.type ==  'R'){
		int i,j;

		int k = s.x;
		int l = s.y;

		i = f.x + 1;
		j = f.y;
		while(1){
			if(i == s.x && j== s.y)
				return true;

			if(grid[i][j] == 1)
				break;
			i++;
			//j++;
		}

		i = f.x - 1;
		j = f.y;
		while(1){
			if(i == s.x && j== s.y)
				return true;

			if(grid[i][j] == 1)
				break;
			i--;
			//j++;
		}

		i = f.x;
		j = f.y - 1;
		while(1){
			if(i == s.x && j== s.y)
				return true;

			if(grid[i][j] == 1)
				break;
			//i++;
			j--;
		}

		i = f.x ;
		j = f.y + 1;
		while(1){
			if(i == s.x && j== s.y)
				return true;

			if(grid[i][j] == 1)
				break;
			j++;
		}

		return false;
	}
	else if(f.type == 'B'){

		int i,j;

		int k = s.x;
		int l = s.y;

		i = f.x + 1;
		j = f.y + 1;
		while(1){
			if(i == s.x && j== s.y)
				return true;

			if(grid[i][j] == 1)
				break;
			i++;
			j++;
		}

		i = f.x - 1;
		j = f.y + 1;
		while(1){
			if(i == s.x && j== s.y)
				return true;

			if(grid[i][j] == 1)
				break;
			i--;
			j++;
		}

		i = f.x + 1;
		j = f.y - 1;
		while(1){
			if(i == s.x && j== s.y)
				return true;

			if(grid[i][j] == 1)
				break;
			i++;
			j--;
		}

		i = f.x - 1;
		j = f.y - 1;
		while(1){
			if(i == s.x && j== s.y)
				return true;

			if(grid[i][j] == 1)
				break;
			i--;
			j--;
		}

		return false;

	}
	else if(f.type == 'N'){

		if( abs(f.x - s.x) == 2 && abs(f.y - s.y) == 1)
			return true;
		else if( abs(f.x - s.x) == 1 && abs(f.y - s.y) == 2)
			return true;
		else
			return false;

	}
	else if(f.type == 'P'){

		if( f.x == (s.x -1) && (abs(f.y - s.y) == 1))
			return true;
		else
			return false;
 	}

 	return false;
}

int main(){

	int t,n,m;

	cin >> t;

	for(int case_t = 1;case_t<= t;case_t++){

		cout << "Case #" << case_t << ":";

		cin >> n;

		int grid[10][10];

		for(int i=0;i<10;i++){
			for(int j=0;j<10;j++){
				if(i >= 1 && i<= 8 && j>= 1&& j<= 8)
					grid[i][j] = 0;
				else
					grid[i][j] = 1;
			}

		}

		vector <guti> board;
		for(int i=0;i<n;i++){
			string str;
			cin >> str;

			guti g;

			g.type = str[3];
			g.y = str[1] - '1' + 1;
			g.x = str[0] - 'A' + 1;

			board.push_back(g);
			grid[g.x][g.y] = 1;
		}

		/*for(vector<guti>::iterator it = board.begin() ; it != board.end(); it++){
			cout << it->type << " " << it->x << " " << it->y << endl;
		}*/

		int len = board.size();

		/*for(int i=0;i<10;i++){
			for(int j=0;j<10;j++){
				cout << grid[i][j] << " ";
			}
			cout << endl;
		}*/

		//cout << endl;
		int cnt = 0;
		for(int i=0;i<len;i++){
			for(int j=0;j<len;j++){
				if(i == j)
					continue;

				if(check( board[i] , board[j], grid)){
					cnt++;
					//cout <<  "yo "<<i << " " << j << endl;
				}
				else{
					//cout <<  "no "<<i << " " << j << endl;
				}
			}
		}


		cout << " " <<cnt;

		cout << endl;
	}


	return 0;
}