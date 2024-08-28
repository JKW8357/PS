#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int dis[1005][1005];

vector<pair<pair<int, int>, int>> houses;
queue<pair<int, int>> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, r, c;
	cin >> n >> m >> r >> c;

	for (int i = 1; i <= n; i++)
		fill(dis[i], dis[i] + m + 1, -1);

	for (int i = 1; i <= r; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		houses.push_back({ { x, y }, z });
	}

	for (int i = 1; i <= c; i++) {
		int x, y;
		cin >> x >> y;
		dis[x][y] = 0;
		q.push({ x,y });
	}

	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
			if (dis[nx][ny] != -1) continue;
			dis[nx][ny] = dis[cur.X][cur.Y] + 1;
			q.push({ nx,ny });
		}
	}

	int ans = INT_MAX;
	for (auto h : houses) ans = min(ans, dis[h.first.X][h.first.Y] * h.second);
	cout << ans << '\n';

	return 0;
}

/*
가중치가 동일할 때, bfs를 통해 처음으로 방문한 곳은 항상 최단거리임이 보장된다.
또한, 방들을 시작점으로 bfs를 수행할 수도, 편의점들을 시작점으로 bfs를 수행할 수도 있다.
이 문제의 경우 여러 방들을 시작점으로 bfs를 돌릴 때, 가중치 z(월세)까지 고려해야 하기 때문에
모든 방들에 대해 bfs를 r번 각각 수행해야 하며, 비효율적이고 TLE가 뜰 가능성이 있다. (O(n * m * r))
따라서 이 문제에서는 여러 편의점들을 시작점으로 bfs를 수행해 방들까지의 최단거리를 한번에 구한 뒤, 
월세를 곱해 한번에 답을 구하는 것이 더욱 효율적이다. (O(n * m))
*/
