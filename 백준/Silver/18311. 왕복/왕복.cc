#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, k;
	cin >> n >> k;

	vector<ll> vec = { 0 };
	for (int i = 0; i < n; i++) {
		ll num;
		cin >> num;
		vec.push_back(vec.back() + num);
	}

	ll pos = (k <= vec.back() ? k : 2 * vec.back() - k);
	ll ans = upper_bound(vec.begin(), vec.end(), pos) - vec.begin();
	cout << (k == vec.back() ? ans - 1 : ans) << '\n';
	return 0;
}