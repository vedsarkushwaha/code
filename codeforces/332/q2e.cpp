#include "bits/stdc++.h"
using namespace std;

const int N = 131420;

typedef vector<int> Array;

int a[N], b[N], f[N];
Array pos[N];

int Solve(int n, int m) {
	bool mkrep = 0;

	for (int i = 0; i < N; ++i) {
		pos[i].clear();
	}
	for (int i = 1; i <= n; ++i) {
		pos[f[i]].push_back(i);
	}
	for (int i = 1; i <= m; ++i) {
		if (0 == pos[b[i]].size()) {
			return -1;
		} else if (1 == pos[b[i]].size()) {
			a[i] = pos[b[i]][0];
		} else {
			mkrep = 1;
		}
	}

	return mkrep;
}

int main() {
	int n, m;

	ios::sync_with_stdio(0);
	while (cin >> n >> m) {
		for (int i = 1; i <= n; ++i) {
			cin >> f[i];
		}
		for (int i = 1; i <= m; ++i) {
			cin >> b[i];
		}
		int ret = Solve(n, m);

		if (0 == ret) {
			cout << "Possible" << endl;
			for (int i = 1; i <= m; ++i) {
				cout << a[i] << ' ';
			}
			cout << endl;
		} else if (1 == ret) {
			cout << "Ambiguity" << endl;
		} else if (-1 == ret) {
			cout << "Impossible" << endl;
		}
	}
	return 0;
}