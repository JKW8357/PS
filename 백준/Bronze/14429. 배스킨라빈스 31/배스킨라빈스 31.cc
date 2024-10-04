#include <bits/stdc++.h>
using namespace std;

int games[1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int j, m;
		cin >> j >> m;
		int r = (j - 1) % (1 + m);
		games[i] = (j - r) / (1 + m) + 1;
	}

	cout << min_element(games + 1, games + n + 1) - games << ' ' << *min_element(games + 1, games + n + 1) * 2 << '\n';
	return 0;
}