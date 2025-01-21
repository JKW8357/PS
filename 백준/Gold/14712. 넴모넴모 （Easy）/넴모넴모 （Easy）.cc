#include <bits/stdc++.h>
using namespace std;

int n, m;
int ans;
bool board[30][30];

void solve(int x, int y) {
	if (x > n) {
		ans++;
		return;
	}

	if (y == m) solve(x + 1, 1);
	else solve(x, y + 1);

	if (!(board[x - 1][y - 1] && board[x - 1][y] && board[x][y - 1])) {
		board[x][y] = true;
		if (y == m) solve(x + 1, 1);
		else solve(x, y + 1);
		board[x][y] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	solve(1, 1);
	cout << ans << '\n';

	return 0;
}