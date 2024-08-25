#include <bits/stdc++.h>
using namespace std;

vector<long long> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		long long num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	
	long long ans = LLONG_MAX;
	for (int i = 0; i < n - 1; i++) {
		auto it = lower_bound(v.begin() + i, v.end(), v[i] + m);
		if (it != v.end()) {
			ans = min(ans, *it - v[i]);
		}
	}
	
	cout << ans << '\n';
	return 0;
}