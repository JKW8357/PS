#include <bits/stdc++.h>
using namespace std;

vector<int> row;
vector<int> col;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, q;
	cin >> n >> m >> q;
	row.assign(n + 1, 0);
	col.assign(m + 1, 0);

	while (q--) {
		int q1, q2, v;
		cin >> q1 >> q2 >> v;
		if (q1 == 1) row[q2] += v;
		else col[q2] += v;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) cout << row[i] + col[j] << ' ';
		cout << '\n';
	}

	return 0;
}