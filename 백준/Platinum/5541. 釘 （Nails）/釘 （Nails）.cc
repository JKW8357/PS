#include <bits/stdc++.h>
using namespace std;

int diff[5005][5005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	while (m--) {
		int a, b, x;
		cin >> a >> b >> x;

		++diff[a][b];
		--diff[a][b + 1];
		--diff[a + x + 1][b];
		++diff[a + x + 1][b + x + 2];
		++diff[a + x + 2][b + 1];
		--diff[a + x + 2][b + x + 2];
	}

	for (int i = 1; i <= n + 2; i++)
		for (int j = 1; j <= i + 2; j++)
			diff[i][j] += diff[i][j - 1];

	for (int i = 1; i <= n + 2; i++)
		for (int j = 1; j <= i + 2; j++)
			diff[i][j] += diff[i - 1][j];
	
	for (int i = 1; i <= n + 2; i++)
		for (int j = 1; j <= i + 2; j++)
			diff[i][j] += diff[i - 1][j - 1];

	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			if (diff[i][j]) ans++;

	cout << ans << '\n';
	return 0;
}