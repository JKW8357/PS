#include <bits/stdc++.h>
using namespace std;

bool isPalindrome[2005][2005];
int arr[2005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	for (int i = 1; i <= n; i++) isPalindrome[i][i] = true;
	for (int i = 1; i <= n - 1; i++)
		if (arr[i] == arr[i + 1]) isPalindrome[i][i + 1] = true;
	for (int length = 3; length <= n; length++) {
		for (int i = 1; i + length - 1 <= n; i++) {
			int j = i + length - 1;
			if (arr[i] == arr[j] && isPalindrome[i + 1][j - 1])
				isPalindrome[i][j] = true;
		}
	}

	int m; cin >> m;
	while (m--) {
		int l, r;
		cin >> l >> r;
		cout << (isPalindrome[l][r] ? 1 : 0) << '\n';
	}

	return 0;
}