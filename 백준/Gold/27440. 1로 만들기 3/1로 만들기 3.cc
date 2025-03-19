#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll bfs(ll n) {
	unordered_map<ll, bool> dis;
	queue<pair<ll, int>> q;
	
	dis[n] = 0;
	q.push({n, 0});

	while (!q.empty()) {
		auto [cur, cnt] = q.front(); q.pop();

		if (cur == 1) return cnt;
		if (dis[cur]) continue;
		dis[cur] = true;

		if (cur % 3 == 0) q.push({ cur / 3, cnt + 1 });

		if (cur % 2 == 0) q.push({ cur / 2, cnt + 1 });

		q.push({ cur - 1, cnt + 1 });
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll n; cin >> n;
	cout << bfs(n) << '\n';

	return 0;
}