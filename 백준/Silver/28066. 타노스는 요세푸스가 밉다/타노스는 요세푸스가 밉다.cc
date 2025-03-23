#include <bits/stdc++.h>
using namespace std;

queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) q.push(i);

	while (q.size() > 1) {
		int f = q.front(); q.pop();
		int cnt = min(k - 1, (int)q.size());
		while (cnt--) q.pop();
		q.push(f);
	}

	cout << q.front() << '\n';
	return 0;
}