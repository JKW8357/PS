#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tc = 0;
	while (true) {
		int n; cin >> n;
		if (n == 0) break;

		int ans = 0;
		while (n != 0) {
			ans += n / 5;
			n /= 5;
		}

		cout << "Case #" << ++tc << ": " << ans << '\n';
	}

	return 0;
}