#include <bits/stdc++.h>
using namespace std;

deque<int> dq;
vector<int> ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, k, m;
	cin >> n >> k >> m;
	for (int i = 1; i <= n; i++) dq.push_back(i);
	bool dir = 0;
	int cnt = 0;
	while (dq.size() > 1) {
		for (int i = 0; i < k - 1; i++) {
			if (dir == 0) {
				dq.push_back(dq.front());
				dq.pop_front();
			}
			else {
				dq.push_front(dq.back());
				dq.pop_back();
			}
		}
		if (dir == 0) {
			ans.push_back(dq.front());
			dq.pop_front();
		}
		else {
			ans.push_back(dq.back());
			dq.pop_back();
		}
		if (++cnt == m) {
			cnt = 0;
			dir = !dir;
		}
	}

	for (int i = 0; i < n - 1; i++) cout << ans[i] << '\n';
	cout << dq.front() << '\n';

	return 0;
}