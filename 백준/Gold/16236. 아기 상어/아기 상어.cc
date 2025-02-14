#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int INF = (int)1e9;

int n;
int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };
vector<vector<int>> board;
vector<vector<int>> dis;

struct Shark {
	int x = 0;
	int y = 0;
	int size = 2;
	int exp = 0;
};

Shark shark;

bool oob(int x, int y) {
	return x < 0 || x >= n || y < 0 || y >= n;
}

void setUp() {
	cin >> n;
	board.resize(n);
	dis.assign(n, vector<int>(n, -1));
	for (int i = 0; i < n; i++) {
		board[i].resize(n);
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 9) {
				shark.x = i;
				shark.y = j;
				board[i][j] = 0;
			}
		}
	}
}

int eatFish() {
	dis.assign(n, vector<int>(n, -1));
	queue<pii> q;
	dis[shark.x][shark.y] = 0;
	q.push({ shark.x, shark.y });

	int minDist = INF;
	pii target = { INF, INF };

	while (!q.empty()) {
		auto [x, y] = q.front(); q.pop();
		int curDist = dis[x][y];

		if (board[x][y] != 0 && board[x][y] < shark.size) {
			if (curDist > minDist) continue;

			else if (curDist < minDist) {
				minDist = curDist;
				target = { x, y };
			}

			else target = min(target, { x, y });
		}

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (oob(nx, ny) || dis[nx][ny] != -1 || board[nx][ny] > shark.size)	continue;
			q.push({ nx, ny });
			dis[nx][ny] = curDist + 1;
		}
	}

	if (minDist == INF) return -1;

	auto [tx, ty] = target;
	board[tx][ty] = 0;

	shark.x = tx; shark.y = ty;
	if (++shark.exp == shark.size) {
		shark.size++;
		shark.exp = 0;
	}

	return minDist;
}

int solve() {
	int result = 0;
	while (true) {
		int time = eatFish();
		if (time == -1) break;
		result += time;
	}
	
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	setUp();
	int totalTime = solve();
	cout << totalTime << '\n';

	return 0;
}