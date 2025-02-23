#include <bits/stdc++.h>
using namespace std;

int dp[1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	dp[1] = 1; 
	dp[2] = 0;
	dp[3] = 1;
	dp[4] = 1;
	dp[5] = 1;
	int n; cin >> n;
	for (int i = 6; i <= n; i++)
		if (!dp[i - 1] || !dp[i - 3] || !dp[i - 4]) dp[i] = 1;
	cout << (dp[n] ? "SK" : "CY") << '\n';

	return 0;
}