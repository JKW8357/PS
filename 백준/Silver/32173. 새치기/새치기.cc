#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	ll ans = 0, tmp = 0;
	for (int i = 1; i <= n; i++) {
		ll num;
		cin >> num;
		if (num - tmp > ans) ans = num - tmp;
		tmp += num;
	}

	cout << ans << '\n';
	return 0;
}