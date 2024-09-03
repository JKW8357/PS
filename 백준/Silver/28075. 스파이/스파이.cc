#include <bits/stdc++.h>
using namespace std;

int n, m;
int ans = 0;
int mission[2][3];

void solve(int day, int status, int place) {
	if (day == n) {
		if (status >= m) ans++;
		return;
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			if (j == place) solve(day + 1, status + mission[i][j] / 2, j);
			else solve(day + 1, status + mission[i][j], j);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
			cin >> mission[i][j];

	solve(0, 0, -1);
	cout << ans << '\n';

	return 0;
}