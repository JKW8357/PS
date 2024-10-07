#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tc;
	cin >> tc;

	while (tc--) {
		int n, c;
		cin >> n >> c;
		cout << (n + c - 1) / c << '\n';
	}

	return 0;
}