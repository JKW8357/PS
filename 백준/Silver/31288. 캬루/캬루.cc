#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int tc; cin >> tc;
	while (tc--) {
		int n; string p;
		cin >> n >> p;

		if (n == 1 && p == "2") {
			cout << 6 << ' ' << 3 << '\n';
			continue;
		}

		int digit_sum = 0;
		for (char c : p) digit_sum += c - '0';
		int k = 3 - digit_sum % 3;

		for (int i = 0; i < n; i++) {
			string new_p = p;
			int digit = new_p[i] - '0';
			new_p[i] = (digit + k <= 9) ? (digit + k + '0') : (digit - (3 - k) + '0');
			cout << new_p << ' ' << 3 << '\n';
		}
	}

	return 0;
}