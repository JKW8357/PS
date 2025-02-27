#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int arr[105];
ll dp[105][25];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	for (int i = 1; i <= n - 1; i++) cin >> arr[i];
	int ans; cin >> ans;

	dp[1][arr[1]] = 1;
	for (int i = 2; i <= n - 1; i++) {
		for (int j = 0; j <= 20; j++) {
			ll pre = dp[i - 1][j];
			if (!pre) continue;

			int add = j + arr[i];
			int sub = j - arr[i];

			if (add <= 20) dp[i][add] += pre;
			if (sub >= 0) dp[i][sub] += pre;
		}
	}

	cout << dp[n - 1][ans] << '\n';
	return 0;
}