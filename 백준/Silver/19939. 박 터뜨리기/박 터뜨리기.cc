#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n, k;
	cin >> n >> k;

	if (n < k * (k + 1) / 2) cout << -1 << '\n';
	else cout << ((n - k * (k + 1) / 2) % k == 0 ? k - 1 : k) << '\n';

	return 0;
}