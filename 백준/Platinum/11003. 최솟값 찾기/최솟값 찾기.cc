#include <bits/stdc++.h>
using namespace std;

deque<pair<int, int>> dq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, l;
	cin >> n >> l;

	for (int i = 0; i < n; i++) {
		int cur; cin >> cur;

		if (!dq.empty() && dq.front().second < i - l + 1) dq.pop_front();
		while (!dq.empty() && dq.back().first >= cur) dq.pop_back();

		dq.push_back({ cur, i });
		cout << dq.front().first << ' ';
	}

	return 0;
}