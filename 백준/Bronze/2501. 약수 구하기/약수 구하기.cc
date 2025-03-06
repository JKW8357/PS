#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, k;
	cin >> n >> k;

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (n % i != 0) continue;
		if (++cnt == k) {
			cout << i << '\n';
			return 0;
		}
	}

	cout << 0 << '\n';
	return 0;
}