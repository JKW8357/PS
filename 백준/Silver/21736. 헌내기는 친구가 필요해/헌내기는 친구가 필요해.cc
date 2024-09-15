#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define X first
#define Y second

int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
char board[605][605];
bool vis[605][605];

int bfs(pii st) {
	int ans = 0;
	queue<pii> q;
	q.push(st);
	vis[st.X][st.Y] = true;

	while (!q.empty()) {
		pii cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (vis[nx][ny] || board[nx][ny] == 'X' || nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] == 'P') ans++;
			pii nxt = { nx, ny };
			q.push(nxt);
			vis[nx][ny] = true;
		}
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	pii st;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'I') st = { i, j };
		}
	}

	int ans = bfs(st);
	if (ans) cout << ans << '\n';
	else cout << "TT\n";
	return 0;
}