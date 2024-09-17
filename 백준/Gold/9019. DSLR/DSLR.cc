#include <bits/stdc++.h>
using namespace std;

bool vis[10005];

string bfs(int a, int b) {
	queue<pair<int, string>> q;
	q.push({ a, "" });
	vis[a] = true;

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		if (cur.first == b) return cur.second;
		
		int nxtd = (cur.first * 2) % 10000;
		if (!vis[nxtd]) {
			q.push({ nxtd, cur.second + "D" });
			vis[nxtd] = true;
		}

		int nxts = (cur.first + 9999) % 10000;
		if (!vis[nxts]) {
			q.push({ nxts, cur.second + "S" });
			vis[nxts] = true;
		}

		int nxtl = (cur.first * 10 + cur.first / 1000) % 10000;
		if (!vis[nxtl]) {
			q.push({ nxtl, cur.second + "L" });
			vis[nxtl] = true;
		}

		int nxtr = cur.first / 10 + (cur.first % 10) * 1000;
		if (!vis[nxtr]) {
			q.push({ nxtr, cur.second + "R" });
			vis[nxtr] = true;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tc;
	cin >> tc;

	while (tc--) {
		int a, b;
		cin >> a >> b;
		fill(vis, vis + 10005, false);
		cout << bfs(a, b) << '\n';
	}
	
	return 0;
}