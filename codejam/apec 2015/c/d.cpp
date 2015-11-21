#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <stack>
#include <queue>
#include <sstream>

using namespace std;

string field[100];
vector<vector<string> > piece;

vector<string> rotate(vector<string> tar) {
	vector<string> ret = vector<string>(tar[0].size());
	for(int i = 0; i < ret.size(); i++) 
	{
		ret[i].resize(tar.size());
		for(int j = 0; j < tar.size(); j++)
			ret[i][j] = tar[j][tar[0].size() - i - 1];
	}

	return ret;
}

int main(void)
{
	piece.resize(8);
	piece[0].push_back("x.");
	piece[0].push_back("xx");
	piece[0].push_back(".x");

	piece[1].push_back(".x");
	piece[1].push_back("xx");
	piece[1].push_back("x.");

	piece[2].push_back("x.");
	piece[2].push_back("x.");
	piece[2].push_back("xx");

	piece[3].push_back(".x");
	piece[3].push_back(".x");
	piece[3].push_back("xx");

	piece[4].push_back("xx");
	piece[4].push_back("xx");
	
	piece[5].push_back("x");
	piece[5].push_back("x");
	piece[5].push_back("x");
	piece[5].push_back("x");

	piece[6].push_back(".x.");
	piece[6].push_back("xxx");

	int T;
	scanf("%d", &T);
	for(int kase = 1; kase <= T; kase++)
	{
		printf("Case #%d:\n", kase);
		int w, h, n;
		scanf("%d %d %d", &w, &h, &n);
		for(int i = 0; i < h; i++)
		{
			field[i] = "";
			for(int j = 0; j < w; j++) field[i] += ".";
		}

		bool isOver = false;
		for(int i = 0; i < n; i++)
		{
			int type, rot, x;
			scanf("%d %d %d", &type, &rot, &x);
			type--;
			if(!isOver)
			{
				auto curPiece = piece[type];
				for(int j = 0; j < rot; j++) curPiece = rotate(curPiece);
				int last = -1;
				for(int j = 0; j < h; j++)
				{
					bool isCross = false;
					for(int k = 0; k < curPiece.size() and !isCross; k++)
					{
						int y = j - (int)curPiece.size() + 1 + k;
						if(y < 0) continue;
						for(int l = 0; l < curPiece[0].size(); l++)
						{
							if(curPiece[k][l] == 'x' and field[y][l + x] == 'x')
							{
								isCross = true;
								break;
							}
						}
					}
					
					if(isCross) break;
					last = j;
				}
				if(last + 1 < curPiece.size()) isOver = true;
				else
				{
					last -= (curPiece.size() - 1);
					for(int j = 0; j < curPiece.size(); j++)
						for(int k = 0; k < curPiece[0].size(); k++)
							if(curPiece[j][k] == 'x')
								field[last + j][x + k] = 'x';

					int ind = h - 1;
					for(int j = h - 1; j >= 0; j--)
					{
						bool isFull = true;
						for(int k = 0; k < w; k++) if(field[j][k] == '.') { isFull = false; break; }
						if(isFull == false) field[ind--] = field[j];
					}
					for(int j = ind; j >= 0; j--) for(int k = 0; k < w; k++) field[j][k] = '.';
				}
			}
		}

		if(isOver) printf("Game Over!\n");
		else for(int i = 0; i < h; i++) printf("%s\n", field[i].c_str());
	}

	return 0;
}
