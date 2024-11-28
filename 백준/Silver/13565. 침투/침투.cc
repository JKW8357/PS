#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int m, n;
string fiber[1005];
bool vis[1005][1005];

void dfs(int x, int y) {
	vis[x][y] = true;
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
		if (fiber[nx][ny] != '0' || vis[nx][ny]) continue;
		dfs(nx, ny);
	}
}

bool check() {
	for (int i = 0; i < n; i++)
		if (vis[m - 1][i]) return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> m >> n;
	for (int i = 0; i < m; i++)	cin >> fiber[i];
	for (int i = 0; i < n; i++) dfs(0, i);
	cout << (check() ? "YES\n" : "NO\n");

	return 0;
}