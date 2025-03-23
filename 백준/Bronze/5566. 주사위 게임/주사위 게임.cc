#include <bits/stdc++.h>
using namespace std;

int board[1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> board[i];

	int cur = 1, cnt = 0;
	while (m--) {
		int d; cin >> d;
		cur += d;
		cur += board[cur];
		cnt++;
		if (cur >= n) break;
	}

	cout << cnt << '\n';
	return 0;
}