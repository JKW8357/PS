#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;

	if (n % 3 == 0 || n % 3 == 1) {
		n -= n % 3;
		cout << 2 * (n / 3) << '\n';
		for (int i = 1; i <= n; i++) {
			if (i % 3 == 0) continue;
			cout << i << ' ';
		}

		cout << '\n' << n / 3 << '\n';
		for (int i = 3; i <= n; i += 3) cout << i << ' ';
	}

	else {
		cout << 1 + 2 * (n - 2) / 3 << '\n';
		cout << 1 << ' ';
		for (int i = 3; i <= n; i += 3) cout << i << ' ' << i + 1 << ' ';

		cout << '\n' << 1 + (n - 2) / 3 << '\n';
		cout << 2 << ' ';
		for (int i = 5; i <= n; i += 3) cout << i << ' ';
	}

	return 0;
}