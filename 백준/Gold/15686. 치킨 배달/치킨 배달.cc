#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, m;
int board[55][55];
vector<pair<int, int>> houses;
vector<pair<int, int>> chickens;

int solve() {
	vector<bool> mask(chickens.size(), true);
	fill(mask.begin(), mask.end() - m, false);

	int ans = INT_MAX;
	do {
		int totDis = 0;
		for (const auto& h : houses) {
			int dis = INT_MAX;
			for (int i = 0; i < chickens.size(); i++) 
				if (mask[i] == 1) dis = min(dis, abs(h.X - chickens[i].X) + abs(h.Y - chickens[i].Y));
			totDis += dis;
		}
		ans = min(ans, totDis);
	} while (next_permutation(mask.begin(), mask.end()));

	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) houses.push_back({ i, j });
			if (board[i][j] == 2) chickens.push_back({ i, j });
		}
	}

	cout << solve() << '\n';	
	return 0;
}