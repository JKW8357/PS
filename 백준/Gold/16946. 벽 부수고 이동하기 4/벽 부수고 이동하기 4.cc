#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

string board[1005];
bool vis[1005][1005];
pair<int, int> zeros[1005][1005];
int output[1005][1005];
int areaNumber = 1;

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	vector<pair<int, int>> zeros_coord = {{ x, y }};
	q.push({ x, y });
	vis[x][y] = true;
	int cnt = 1;

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (vis[nx][ny] || board[nx][ny] == '1') continue;
			q.push({ nx, ny });
			vis[nx][ny] = true;
			zeros_coord.push_back({ nx, ny });
			cnt++;
		}
	}

	areaNumber++;
	for (const auto& e : zeros_coord) {
		zeros[e.X][e.Y] = { areaNumber, cnt };
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> board[i];
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (!vis[i][j] && board[i][j] == '0') bfs(i, j);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == '1') {
				output[i][j] = 1;
				vector<int> used;
				for (int dir = 0; dir < 4; dir++) {
					int nx = i + dx[dir];
					int ny = j + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					int currentAreaNumber = zeros[nx][ny].first;
					if (currentAreaNumber == 0 || find(used.begin(), used.end(), currentAreaNumber) != used.end()) continue;
					used.push_back(currentAreaNumber);
					output[i][j] += zeros[nx][ny].second;
				}
				output[i][j] %= 10;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cout << output[i][j];
		cout << '\n';
	}
		
	return 0;
}