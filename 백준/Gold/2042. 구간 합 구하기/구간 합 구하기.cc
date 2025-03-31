#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, k;
vector<ll> BIT;
vector<ll> arr;

ll sum(int idx) {
	ll result = 0;
	while (idx) {
		result += BIT[idx];
		idx -= (idx & -idx);
	}
	return result;
}

void update(int idx, ll val) {
	while (idx < (int)BIT.size()) {
		BIT[idx] += val;
		idx += (idx & -idx);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m >> k;
	BIT.assign(n + 1, 0);
	arr.assign(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		ll x; cin >> x;
		arr[i] = x;
		update(i, x);
	}

	int q = m + k;
	while (q--) {
		int query; cin >> query;
		if (query == 1) {
			int idx; ll val;
			cin >> idx >> val;
			ll diff = val - arr[idx];
			arr[idx] = val;
			update(idx, diff);
		}
		else {
			int st, en;
			cin >> st >> en;
			cout << sum(en) - sum(st - 1) << '\n';
		}
	}

	return 0;
}