#include <bits/stdc++.h>
using namespace std;

bool isPalindrome[2505][2505];
int dp[2505];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str; cin >> str;
	int n = (int)str.size();

	for (int i = 1; i <= n; i++) isPalindrome[i][i] = true;

	for (int i = 1; i <= n - 1; i++)
		if (str[i - 1] == str[i]) isPalindrome[i][i + 1] = true;

	for (int length = 3; length <= n; length++) {
		for (int i = 1; i + length - 1 <= n; i++) {
			int j = i + length - 1;
			if (str[i - 1] == str[j - 1] && isPalindrome[i + 1][j - 1])
				isPalindrome[i][j] = true;
		}
	}

	for (int j = 1; j <= n; j++) {
		dp[j] = j;
		for (int i = 1; i <= j; i++)
			if (isPalindrome[i][j]) 
				dp[j] = min(dp[j], dp[i - 1] + 1);
	}

	cout << dp[n] << '\n';
	return 0;
}