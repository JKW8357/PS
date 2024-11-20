#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll s, c;
ll arr[1000005];

bool param(ll mid) {
	ll cnt = 0;
	for (int i = 0; i < s; i++) if (arr[i] >= mid) cnt += arr[i] / mid;
	return cnt >= c;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll sum = 0;
	cin >> s >> c;
	for (int i = 0; i < s; i++) {
		cin >> arr[i];
		sum += arr[i];
	}

	ll lo = 0, hi = 1e9 + 1;
	while (lo + 1 < hi) {
		ll mid = midpoint(lo, hi);
		if (param(mid)) lo = mid;
		else hi = mid;
	}

	ll ans = sum - lo * c;
	cout << ans << '\n';
	return 0;
}