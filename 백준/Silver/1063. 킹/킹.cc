#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

string board[10][10];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string k, s;
	int n;
	cin >> k >> s >> n;

	pair<int, int> king, stone;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			board[i][j] += 'A' + j;
			board[i][j] += to_string(8 - i);
			if (k == board[i][j]) king = { i, j };
			if (s == board[i][j]) stone = { i, j };
		}
	}

	while (n--) {
		string cmd;
		cin >> cmd;
		int kx = 0, ky = 0;

		if (cmd[0] == 'R') {
			ky++;
			if (cmd.size() > 1 && cmd[1] == 'B') kx++;;
			if (cmd.size() > 1 && cmd[1] == 'T') kx--;
		}
		if (cmd[0] == 'L') {
			ky--;
			if (cmd[1] == 'B') kx++;;
			if (cmd[1] == 'T') kx--;
		}
		if (cmd[0] == 'B') kx++;
		if (cmd[0] == 'T') kx--;

		int nkx = king.X + kx;
		int nky = king.Y + ky;
		int nsx = stone.X + kx;
		int nsy = stone.Y + ky;

		if (nkx < 0 || nkx >= 8 || nky < 0 || nky >= 8) continue;
		if (stone.X == nkx && stone.Y == nky) {
			if (nsx < 0|| nsx >= 8 || nsy < 0 || nsy >= 8) continue;
			stone = { nsx, nsy };
		}
		king = { nkx, nky };
	}

	cout << board[king.X][king.Y] << '\n' << board[stone.X][stone.Y];
	return 0;
}