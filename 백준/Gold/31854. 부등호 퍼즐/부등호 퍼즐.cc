#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

vector<pii> adj[1005][1005];
int deg[1005][1005];
int result[1005][1005];
int n;

void topologicalSort() {
	queue<pii> q;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (deg[i][j] == 0) q.push({ i, j });

	int num = 0;
	while (!q.empty()) {
		auto [x, y] = q.front(); q.pop();
		result[x][y] = ++num;
		for (auto [nx, ny] : adj[x][y]) {
			deg[nx][ny]--;
			if (deg[nx][ny] == 0) q.push({ nx, ny });
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) cout << result[i][j] << ' ';
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n - 1; j++) {
			char ch; cin >> ch;
			if (ch == '<') {
				adj[i][j].push_back({ i, j + 1 });
				deg[i][j + 1]++;
			}
			else {
				adj[i][j + 1].push_back({ i, j });
				deg[i][j]++;
			}
		}
	}

	for (int i = 1; i <= n - 1; i++) {
		for (int j = 1; j <= n; j++) {
			char ch; cin >> ch;
			if (ch == '<') {
				adj[i][j].push_back({ i + 1, j });
				deg[i + 1][j]++;
			}
			else {
				adj[i + 1][j].push_back({ i, j });
				deg[i][j]++;
			}
		}
	}

	topologicalSort();
	return 0;
}