#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> apples(100005);
vector<int> adj[100005];

int dfs(int cur, int dist) {
	int result = apples[cur];
	if (dist == k) return result;

	for (int nxt : adj[cur])
		result += dfs(nxt, dist + 1);

	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> k;
	for (int i = 0; i < n - 1; i++) {
		int p, c;
		cin >> p >> c;
		adj[p].push_back(c);
	}

	for (int i = 0; i < n; i++) cin >> apples[i];

	cout << dfs(0, 0) << '\n';
	return 0;
}