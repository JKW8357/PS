#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

string LCS(const string& a, const string& b) {
	int n = a.size();
	int m = b.size();

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1; // 두 문자가 같으면, 공통 부분 수열에 그 문자를 추가
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // 두 문자가 다르면, 하나의 문자열에서 문자를 빼고 계산한 LCS 중 더 긴 값을 취함
		}
	}

	string result;
	int i = n, j = m;
	while (i > 0 && j > 0) {
		if (a[i - 1] == b[j - 1]) {
			result += a[i - 1];  // 공통 문자라면 LCS 문자열에 추가 후 왼쪽 위로 이동
			i--; j--;
		}

		else if (dp[i - 1][j] > dp[i][j - 1]) i--;  // 위쪽 값이 더 크면 위쪽으로 이동

		else j--;  // 왼쪽 값이 더 크면 왼쪽으로 이동
	}

	reverse(result.begin(), result.end()); // 역순으로 추가했으므로 결과를 뒤집음
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string a, b;
	cin >> a >> b;
	
	string ans = LCS(a, b);
	cout << ans.size() << '\n' << ans << '\n';

	return 0;
}