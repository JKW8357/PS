#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tc;
	cin >> tc;
	while (tc--) {
		int a, b;
		cin >> a >> b;
		cout << (a + b) * (a + b - 1) / 2 * (a + b) << '\n';
	}

	return 0;
}