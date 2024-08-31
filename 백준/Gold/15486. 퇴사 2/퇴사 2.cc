#include <bits/stdc++.h>
using namespace std;

int dp[1500005]; // dp[i] : i일까지의 누적 최대 수익

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int t, p;
		cin >> t >> p;

		// i일에 상담을 하는 경우, 상담이 끝나는 날(i + t)에 최대 수익을 갱신
		if (i + t <= n + 1) dp[i + t] = max(dp[i + t], dp[i] + p);

		// i일에 상담을 하지 않는 경우, 다음 날(i + 1)로 최대 수익을 이어받음
		dp[i + 1] = max(dp[i + 1], dp[i]);
	}

	cout << dp[n + 1] << '\n';
	return 0;
}