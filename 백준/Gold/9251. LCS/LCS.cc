#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int LCS(const string& a, const string& b) {
	int n = a.size();
	int m = b.size();

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1; // 두 문자가 같으면, 공통 부분 수열에 그 문자를 추가
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // 두 문자가 다르면, 하나의 문자열에서 문자를 빼고 계산한 LCS 중 더 긴 값을 취함
		}
	}

	return dp[n][m];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string a, b;
	cin >> a >> b;
	cout << LCS(a, b) << '\n';

	return 0;
}