#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<int, int>> towns;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	towns.assign(n, {});
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		int x, a;
		cin >> x >> a;
		towns[i] = { x, a };
		sum += a;
	}

	sort(towns.begin(), towns.end());
	ll cnt = 0;
	for (auto& [x, a] : towns) {
		cnt += a;
		if (cnt >= (sum + 1) / 2) {
			cout << x << '\n';
			return 0;
		}
	}
}