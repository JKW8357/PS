#include <bits/stdc++.h>
using namespace std;

int arr[250005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	while (q--) {
		int x, y;
		cin >> x >> y;

		int row = max(arr[y] - x + 1, 0);
		int col = lower_bound(arr + y + 1, arr + n + 1, x - 1, greater<int>()) - (arr + y + 1);
		int ans = row + col;

		cout << ans << '\n';
	}

	return 0;
}