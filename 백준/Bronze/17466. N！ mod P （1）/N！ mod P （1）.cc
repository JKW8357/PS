#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, p;
	cin >> n >> p;

	ll ans = 1;
	for (int i = 2; i <= n; i++) {
		ans *= i;
		ans %= p;
	}

	cout << ans << '\n';
	return 0;
}