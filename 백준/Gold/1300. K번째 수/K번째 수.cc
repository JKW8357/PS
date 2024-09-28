#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, k;
bool param(ll num) {
	ll cnt = 0;
	for (int i = 1; i <= n; i++) {
		cnt += min(n, num / i);
		if (cnt >= k) break;
	}
	return cnt >= k;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	ll lo = 0, hi = 1e10;
	while (lo + 1 < hi) {
		ll mid = midpoint(lo, hi);
		if (param(mid)) hi = mid;
		else lo = mid;
	}

	cout << hi << '\n';
	return 0;
}