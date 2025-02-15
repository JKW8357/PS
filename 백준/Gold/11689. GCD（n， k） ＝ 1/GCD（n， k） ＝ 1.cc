#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll eulerPhi(ll n) {
	ll result = n;
	for (ll p = 2; p * p <= n; p++) {
		if (n % p != 0) continue;
		while (n % p == 0) n /= p;
		result -= result / p;
	}
	if (n > 1) result -= result / n;
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll n; cin >> n;
	cout << eulerPhi(n) << '\n';

	return 0;
}