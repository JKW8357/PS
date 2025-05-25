#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int n;
int houseCount = 0;
int groupCount = 0;
vector<int> houses;
string board[25];
bool vis[25][25];

void dfs(int x, int y) {
	vis[x][y] = true;
	houseCount++;
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
		if (vis[nx][ny] || board[nx][ny] == '0') continue;
		dfs(nx, ny);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> board[i];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vis[i][j] || board[i][j] == '0') continue;
			groupCount++;
			houseCount = 0;
			dfs(i, j);
			houses.push_back(houseCount);
		}
	}

	cout << groupCount << '\n';
	sort(houses.begin(), houses.end());
	for (auto i : houses) cout << i << '\n';

	return 0;
}