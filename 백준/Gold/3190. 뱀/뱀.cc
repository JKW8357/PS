#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int board[105][105];

queue<pair<int, char>> turn;
deque<pair<int, int>> snake;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	while (k--) {
		int x, y;
		cin >> x >> y;
		board[x][y] = -1;
	}

	int l;
	cin >> l;

	while (l--) {
		int t;
		char d;
		cin >> t >> d;
		turn.push({ t, d });
	}

	int dir = 0;
	int time = 0;
	snake.push_back({ 1, 1 });

	while (true) {
		time++;
		int nx = snake.front().X + dx[dir];
		int ny = snake.front().Y + dy[dir];

		if (nx <= 0 || nx > n || ny <= 0 || ny > n || board[nx][ny] == 1) break;

		if (!turn.empty() && time == turn.front().first) {
			if (turn.front().second == 'L') dir = (dir + 3) % 4;
			else dir = (dir + 1) % 4;
			turn.pop();
		}

		if (board[nx][ny] != -1) {
			board[snake.back().X][snake.back().Y] = 0;
			snake.pop_back();
		}

		board[nx][ny] = 1;
		snake.push_front({ nx, ny });
	}

	cout << time << '\n';
	return 0;
}