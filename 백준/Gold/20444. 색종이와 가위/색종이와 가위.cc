#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll n, k;
	cin >> n >> k;
	
	ll lo = -1, hi = n / 2 + 1;
	while (lo + 1 < hi) {
		ll mid = (lo + hi) / 2;
		ll calc = mid * (n - mid) + n + 1;
		if (calc == k) {
			cout << "YES\n";
			return 0;
		}
		else if (calc < k) lo = mid;
		else hi = mid;
	}

	cout << "NO\n";
	return 0;
}