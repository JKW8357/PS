#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, k;
ll arr[500005];

bool param(ll num) {
	ll sum = 0;
	for (int i = 0; i < n; i++) 
		if (arr[i] > num) sum += (arr[i] - num);
	return sum <= k;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> arr[i];

	ll lo = -1, hi = 1e12 + 1;
	while (lo + 1 < hi) {
		ll mid = midpoint(lo, hi);
		if (param(mid)) hi = mid;
		else lo = mid;
	}

	cout << hi << '\n';
	return 0;
}