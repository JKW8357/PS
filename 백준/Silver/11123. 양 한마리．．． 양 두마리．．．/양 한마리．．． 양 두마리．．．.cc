#include <bits/stdc++.h>
using namespace std;

int h, w;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

char arr[105][105];
bool vis[105][105];

void dfs(int x, int y) {
	vis[x][y] = true;
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
		if (arr[nx][ny] != '#' || vis[nx][ny]) continue;
		dfs(nx, ny);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tc;
	cin >> tc;

	while (tc--) {
		cin >> h >> w;
	
		for (int i = 0; i < h; i++)
			fill(vis[i], vis[i] + w, false);

		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				cin >> arr[i][j];

		int cnt = 0;
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				if (arr[i][j] == '#' && !vis[i][j]) { dfs(i, j); cnt++; }
		
		cout << cnt << '\n';
	}

	return 0;
}