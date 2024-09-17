#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tc;
	cin >> tc;

	while (tc--) {
		string str;
		cin >> str;

		int dir = 0;
		int MX = 0, mx = 0, MY = 0, my = 0;
		pair<int, int> turtle = { 0,0 };

		for (char c : str) {
			if (c == 'F') {
				turtle.X += dx[dir];
				turtle.Y += dy[dir];
			}

			else if (c == 'B') {
				turtle.X -= dx[dir];
				turtle.Y -= dy[dir];
			}

			else if (c == 'L') dir = (dir + 3) % 4;

			else dir = (dir + 1) % 4;

			MX = max(MX, turtle.X);
			mx = min(mx, turtle.X);
			MY = max(MY, turtle.Y);
			my = min(my, turtle.Y);
		}

		int ans = (MX - mx) * (MY - my);
		cout << ans << '\n';
	}

	return 0;
}