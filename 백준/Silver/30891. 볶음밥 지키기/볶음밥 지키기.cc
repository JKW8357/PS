#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

pair<int, int> arr[105];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, r;
	cin >> n >> r;

	for (int i = 1; i <= n; i++) cin >> arr[i].X >> arr[i].Y;

	int max_val = 0;
	pair<int, int> ans;
	for (int i = -100; i <= 100; i++) {
		for (int j = -100; j <= 100; j++) {
			int cnt = 0;
			for (int k = 1; k <= n; k++)
				if (hypot((i - arr[k].X), (j - arr[k].Y)) <= r) cnt++;
			if (max_val < max(max_val, cnt)) {
				max_val = max(max_val, cnt);
				ans = { i,j };
			}
		}
	}

	cout << ans.X << ' ' << ans.Y << '\n';
	return 0;
}