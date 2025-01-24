#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tc; cin >> tc;
	while (tc--) {
		int x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		
		ll dx = x2 - x1, dy = y2 - y1;
		ll d = dx * dx + dy * dy;
		ll r_sum = (r1 + r2) * (r1 + r2), r_sub = (r1 - r2) * (r1 - r2);

		int ans = 0;
		if (d == 0 && r_sub == 0) ans = -1;
		else if (r_sum < d || d < r_sub) ans = 0;
		else if (r_sum == d || d == r_sub) ans = 1;
		else ans = 2;

		cout << ans << '\n';
	}

	return 0;
}