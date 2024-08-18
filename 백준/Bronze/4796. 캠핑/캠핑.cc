#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 1; ; i++) {
		int l, p, v;
		cin >> l >> p >> v;

		if (l == 0 && p == 0 && v == 0) break;

		int ans = 0;
		ans += (v / p) * l + min(v % p, l);

		cout << "Case " << i << ": " << ans << '\n';
	}

	return 0;
}