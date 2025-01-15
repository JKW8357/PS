#include <bits/stdc++.h>
using namespace std;

int n;
int ans = 0;
int col, diag1, diag2;

void solve(int depth) {
	if (depth == n) {
		ans++;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (col & (1 << i) || diag1 & (1 << (i - depth + n - 1)) || diag2 & (1 << (i + depth))) continue;
		col |= (1 << i);
		diag1 |= (1 << (i - depth + n - 1));
		diag2 |= (1 << (i + depth));

		solve(depth + 1);

		col &= ~(1 << i);
		diag1 &= ~(1 << (i - depth + n - 1));
		diag2 &= ~(1 << (i + depth));
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	solve(0);
	cout << ans << '\n';

	return 0;
}