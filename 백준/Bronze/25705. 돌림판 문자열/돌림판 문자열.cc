#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	string board, target;
	cin >> n >> board >> m >> target;

	int bs = board.size();
	int ts = target.size();
	int curPos = bs - 1;
	int idx = 0;
	int cnt = 0;

	while (idx < ts) {
		bool found = false;
		int searchPos = curPos;

		do {
			searchPos = (searchPos + 1) % bs;
			cnt++;
			if (board[searchPos] == target[idx]) {
				found = true;
				curPos = searchPos;
				idx++;
				break;
			}
		} while (searchPos != curPos);

		if (!found) {
			cout << -1 << '\n';
			return 0;
		}
	}

	cout << cnt << '\n';
	return 0;
}
