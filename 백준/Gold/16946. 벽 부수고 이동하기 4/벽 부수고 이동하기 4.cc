#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

string board[1005];
int p[1000005]; // 좌표를 저장하는 Disjoint-Set
int areaSize[1000005];
int output[1005][1005];

int coordToId(int x, int y) {
	return x * m + y; // 2D 좌표를 1D ID로 변환
}

int find(int x) {
	if (p[x] == x) return x;
	return p[x] = find(p[x]);
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) {
		p[b] = a;
		areaSize[a] += areaSize[b];
	}
}

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	int rootId = coordToId(x, y); // 현재 영역의 루트 ID
	p[rootId] = rootId;
	areaSize[rootId] = 1;
	board[x][y] = '2'; // 별도의 vis 배열을 사용하지 않고 방문 처리

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] != '0') continue;

			q.push({ nx, ny });
			board[nx][ny] = '2';
			int neighborId = coordToId(nx, ny);
			p[neighborId] = rootId; // 같은 영역으로 합침
			areaSize[rootId]++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> board[i];
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (board[i][j] == '0') bfs(i, j);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == '1') {
				output[i][j] = 1;
				set<int> used;

				for (int dir = 0; dir < 4; dir++) {
					int nx = i + dx[dir];
					int ny = j + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

					if (board[nx][ny] == '2') { // 방문한 0 영역만 고려
						int rootId = find(coordToId(nx, ny));
						if (used.count(rootId)) continue;
						used.insert(rootId);
						output[i][j] += areaSize[rootId];
					}
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