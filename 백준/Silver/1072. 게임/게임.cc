#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll x, y;
	cin >> x >> y;
	ll z = y * 100 / x;

	ll ans = 0;
	if (z >= 99) cout << -1 << '\n';
	else {
		ll st = 1, en = 1e9;
		while (st <= en) {
			ll mid = (st + en) / 2;
			if ((y + mid) * 100 / (x + mid) > z) {
				ans = mid;
				en = mid - 1;
			}
			else st = mid + 1;
		}
		cout << ans << '\n';
	}
	return 0;
}