#include <bits/stdc++.h>
using namespace std;

int n, m;
string board[1005];
int p[1000005];
bool vis[1005][1005];
unordered_map<char, pair<int, int>> dir = {
	{ 'U', { -1, 0 } },
	{ 'D', { 1, 0 } },
	{ 'L', { 0, -1 } },
	{ 'R', { 0, 1 } },
};

int coordToId(int x, int y) {
	return x * m + y;
}

int find(int x) {
	if (p[x] == x) return x;
	return p[x] = find(p[x]);
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) p[b] = a;
}

void dfs(int x, int y) {
	vis[x][y] = true;

	auto [dx, dy] = dir[board[x][y]];
	int nx = x + dx;
	int ny = y + dy;

	unite(coordToId(x, y), coordToId(nx, ny));
	if (!vis[nx][ny]) dfs(nx, ny);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> board[i];
	for (int i = 0; i < n * m; i++) p[i] = i;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vis[i][j]) continue;
			dfs(i, j);
		}
	}

	set<int> s;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			s.insert(find(coordToId(i, j)));

	cout << s.size() << '\n';
	return 0;
}