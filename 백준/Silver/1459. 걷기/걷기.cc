#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll x, y, w, s;
	cin >> x >> y >> w >> s;

	ll ans = 0;
	ans += min(x, y) * min(2 * w, s);
	ll left = max(x, y) - min(x, y);
	if (left % 2 != 0) ans += w;
	ans += left / 2 * 2 * min(w, s);
	cout << ans << '\n';

	return 0;
}