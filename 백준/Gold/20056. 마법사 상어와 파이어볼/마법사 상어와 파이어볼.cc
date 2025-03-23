#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,1,1,1,0,-1,-1,-1 };

struct fireBall { int x, y, mass, speed, direction; };
vector<fireBall> fireBalls;

void moveFireBall() {
	for (auto& [x, y, mass, speed, direction] : fireBalls) {
		int moveX = (dx[direction] * speed % n) % n;
		int moveY = (dy[direction] * speed % n) % n;
		x = (x + (moveX + n)) % n;
		y = (y + (moveY + n)) % n;
	}
}

void mergeAndSplitFireBall() {
	vector<vector<vector<fireBall>>> board(n, vector<vector<fireBall>>(n));
	for (auto& f : fireBalls) board[f.x][f.y].push_back(f);
	fireBalls.clear();

	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			if (board[x][y].empty()) continue;
			if (board[x][y].size() == 1) {
				fireBalls.push_back(board[x][y][0]);
				continue;
			}

			int massSum = 0;
			int speedSum = 0;
			int cnt = board[x][y].size();
			bool allDirOdd = true;
			bool allDirEven = true;

			for (auto& [fx, fy, m, s, d] : board[x][y]) {
				massSum += m;
				speedSum += s;
				if (d % 2 == 0) allDirOdd = false;
				else allDirEven = false;
			}

			int newMass = massSum / 5;
			int newSpeed = speedSum / cnt;
			int st = (allDirOdd || allDirEven ? 0 : 1);
			if (newMass == 0) continue;

			for (int dir = st; dir < 8; dir += 2) {
				fireBall newFireBall = { x, y, newMass, newSpeed, dir };
				fireBalls.push_back(newFireBall);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m >> k;
	fireBalls.reserve(m);
	for (int i = 0; i < m; i++) {
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		fireBalls.push_back({ --r, --c, m, s, d });
	}

	while (k--) {
		moveFireBall();
		mergeAndSplitFireBall();
	}

	int totalMass = 0;
	for (auto& f : fireBalls) totalMass += f.mass;
	cout << totalMass << '\n';

	return 0;
}