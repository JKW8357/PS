#include <bits/stdc++.h>
using namespace std;

int arr[25][25];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	vector<bool> mask(n, true);
	fill(mask.begin(), mask.end() - n / 2, false);

	int ans = INT_MAX;
	do {
		int diff = 0;
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (mask[i] != mask[j]) continue;
				if (mask[i]) diff += (arr[i][j] + arr[j][i]);
				else diff -= (arr[i][j] + arr[j][i]);
			}
		}
		ans = min(ans, abs(diff));
	} while (next_permutation(mask.begin(), mask.end()));

	cout << ans << '\n';
	return 0;
}