#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll k) {
	if (k == 1) return 0;
	ll p = 1;
	while (k > 2 * p) p *= 2;
	return 1 - solve(k - p);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll k; cin >> k;
	cout << solve(k) << '\n';

	return 0;
}