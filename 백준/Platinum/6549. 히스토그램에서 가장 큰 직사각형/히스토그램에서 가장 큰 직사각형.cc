#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
vector<ll> arr;

ll solve(ll st, ll en) {
	if (st == en) return 0;
	if (st + 1 == en) return arr[st];

	ll mid = (st + en) / 2;
	ll result = max(solve(st, mid), solve(mid, en));

	ll l = mid - 1;
	ll r = mid;
	ll h = min(arr[l], arr[r]);
	result = max(result, h * 2);

	while (l > st || r < en - 1) {
		if (l > st && r < en - 1) {
			if (arr[l - 1] >= arr[r + 1]) h = min(h, arr[--l]);
			else h = min(h, arr[++r]);
		}

		else if (l > st) h = min(h, arr[--l]);
		else if (r < en - 1) h = min(h, arr[++r]);

		result = max(result, h * (r - l + 1));
	}

	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (true) {
		cin >> n;
		if (n == 0) break;

		arr.resize(n);
		for (int i = 0; i < n; i++) cin >> arr[i];

		ll ans = solve(0, n);
		cout << ans << '\n';
	}

	return 0;
}