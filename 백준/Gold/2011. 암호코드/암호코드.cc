#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e6;

int dp[5005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string password;
	cin >> password;
	int n = (int)password.size();

	if (password[0] == '0') {
		cout << 0 << '\n';
		return 0;
	}

	dp[0] = 1; dp[1] = 1;
	for (int i = 2; i <= n; i++) {		
		int pre = password[i - 2] - '0';
		int cur = password[i - 1] - '0';
		int tmp = 10 * pre + cur;

		if (cur != 0) dp[i] = (dp[i] + dp[i - 1]) % MOD;
        if (tmp >= 10 && tmp <= 26) dp[i] = (dp[i] + dp[i - 2]) % MOD;
	}
    
	cout << dp[n] << '\n';
	return 0;
}