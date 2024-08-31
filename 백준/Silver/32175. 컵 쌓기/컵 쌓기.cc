#include <bits/stdc++.h>
using namespace std;

int arr[105];
long long dp[100005];

int mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, h;
	cin >> n >> h;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	
	dp[0] = 1;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= n; j++) {
			if (i - arr[j] >= 0) {
				dp[i] += dp[i - arr[j]];
				dp[i] %= mod;
			}
		}
	}

	cout << dp[h] << '\n';
	return 0;
}