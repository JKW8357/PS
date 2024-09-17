#include <bits/stdc++.h>
using namespace std;

string board[105];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int h, w;
	cin >> h >> w;

	for (int i = 0; i < h; i++) cin >> board[i];

	int ans = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (board[i][j] != '.') {
				int tmp = board[i].find_first_not_of('.', j + 1);
				ans += tmp - j;
				j = tmp;
			}
		}
	}

	cout << ans << '\n';
	return 0;
}