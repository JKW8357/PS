#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	string board, target;
	cin >> n >> board >> m >> target;

	string str;
	int bs = board.size();
	int cur = bs - 1;
	int idx = 0;
	int cnt = 0;

	while (idx < target.size()) {
		int tmp = cur;
		do {
			tmp = (tmp + 1) % bs;
			cnt++;

			if (board[tmp] == target[idx]) {
				str += target[idx];
				break;
			}
		} while (tmp != cur);

		idx++;
		cur = tmp;
		if (str.size() != idx) {
			cout << -1 << '\n';
			return 0;
		}
	}

	cout << cnt << '\n';
	return 0;
}