#include <bits/stdc++.h>
using namespace std;

int f[30];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	f[0] = 0; f[1] = 1;
	for (int i = 2; i <= 30; i++) f[i] = f[i - 1] + f[i - 2];

	int tc; cin >> tc;
	while (tc--) {
		int x, y;
		cin >> x >> y;

		for (int i = 30; i >= 1; i--) {
			if (f[i] <= x && f[i - 1] <= y) {
				cout << f[i] << ' ' << f[i - 1] << '\n';
				break;
			}
		}
	}

	return 0;
}