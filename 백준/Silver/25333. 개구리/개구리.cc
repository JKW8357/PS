#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tc;
	cin >> tc;

	while (tc--) {
		int a, b, x;
		cin >> a >> b >> x;
		cout << x / gcd(a, b) << '\n';
	}

	return 0;
}