#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tc;
	cin >> tc;

	while (tc--) {
		vector<pair<int, int>> v;
		for (int i = 0; i < 4; i++) {
			int x, y;
			cin >> x >> y;
			v.push_back({ x, y });
		}
		sort(v.begin(), v.end());

		vector<double> len;
		for (int i = 1; i <= 2; i++) {
			len.push_back(hypot(v[0].X - v[i].X, v[0].Y - v[i].Y));
			len.push_back(hypot(v[3].X - v[i].X, v[3].Y - v[i].Y));
		}

		bool check1 = (len[0] == len[1] && len[0] == len[2] && len[0] == len[3]);
		bool check2 = (hypot(v[3].X - v[0].X, v[3].Y - v[0].Y) == hypot(v[2].X - v[1].X, v[2].Y - v[1].Y));

		cout << (check1 && check2 ? 1 : 0) << '\n';
	}

	return 0;
}