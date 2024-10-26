#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (true) {
		long long n; cin >> n;
		if (n == 0) break;
		cout << n * (n + 1) / 2 << '\n';
	}

	return 0;
}