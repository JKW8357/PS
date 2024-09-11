#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int y = 0, m = 0;
	while (n--) {
		int t;
		cin >> t;
		y += (t / 30 + 1) * 10;
		m += (t / 60 + 1) * 15;
	}

	if (y <= m) cout << "Y ";
	if (y >= m) cout << "M ";
	cout << min(y, m) << '\n';

	return 0;
}