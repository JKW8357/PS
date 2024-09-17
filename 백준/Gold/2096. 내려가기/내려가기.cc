#include <bits/stdc++.h>
using namespace std;

int max_dp[3];
int min_dp[3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int max_tmp1 = 0, max_tmp2 = 0, max_tmp3 = 0;
	int min_tmp1 = 0, min_tmp2 = 0, min_tmp3 = 0;
	for (int i = 1; i <= n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		max_dp[0] = max(max_tmp1, max_tmp2) + a;
		min_dp[0] = min(min_tmp1, min_tmp2) + a;

		max_dp[1] = max({ max_tmp1, max_tmp2, max_tmp3 }) + b;
		min_dp[1] = min({ min_tmp1, min_tmp2, min_tmp3 }) + b;

		max_dp[2] = max(max_tmp2, max_tmp3) + c;
		min_dp[2] = min(min_tmp2, min_tmp3) + c;

		max_tmp1 = max_dp[0], max_tmp2 = max_dp[1], max_tmp3 = max_dp[2];
		min_tmp1 = min_dp[0], min_tmp2 = min_dp[1], min_tmp3 = min_dp[2];
	}

	cout << *max_element(max_dp, max_dp + 3) << ' ' << *min_element(min_dp, min_dp + 3) << '\n';
	return 0;
}