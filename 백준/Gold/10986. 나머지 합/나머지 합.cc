#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int sum[1000005];
ll cnt[1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	cnt[0] = 1;
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		sum[i] = sum[i - 1] + num % m;
		sum[i] %= m;
		cnt[sum[i]]++;
	}

	ll ans = 0;
	for (int i = 0; i < m; i++) 
		if (cnt[i] >= 2) ans += cnt[i] * (cnt[i] - 1) / 2;
	cout << ans << '\n';

	return 0;
}