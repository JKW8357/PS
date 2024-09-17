#include <bits/stdc++.h>
using namespace std;

int arr[105][105];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	int ans = (n * m) * 2;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) 
			cin >> arr[i][j];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) ans += abs(arr[i][j] - arr[i][j - 1]);
		ans += arr[i][m];
	}


	for (int j = 1; j <= m; j++) {
		for (int i = 1; i <= n; i++) ans += abs(arr[i][j] - arr[i - 1][j]);
		ans += arr[n][j];
	}

	cout << ans << '\n';
	return 0;
}