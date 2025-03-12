#include <bits/stdc++.h>
using namespace std;

queue<int> q;
vector<int> ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) q.push(i);
	while (q.size() > 1) {
		for (int i = 0; i < k - 1; i++) {
			q.push(q.front());
			q.pop();
		}

		ans.push_back(q.front());
		q.pop();
	}

	cout << '<';
	for (int i = 0; i < n - 1; i++) cout << ans[i] << ", ";
	cout << q.front() << '>';

	return 0;
}