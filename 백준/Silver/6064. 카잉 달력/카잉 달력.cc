#include <bits/stdc++.h>
using namespace std;

int solve(int m, int n, int x, int y) {
	int LCM = lcm(m, n);
	for (int i = x; i <= LCM; i += m) {
		if (i % n == (n == y ? 0 : y)) return i;
	}
	return -1;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		int m, n, x, y;
		cin >> m >> n >> x >> y;
		cout << solve(m, n, x, y) << '\n';
	}
}