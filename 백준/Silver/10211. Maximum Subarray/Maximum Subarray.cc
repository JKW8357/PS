#include <bits/stdc++.h>
using namespace std;

int arr[1005];
int sum[1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int tc; cin >> tc;
	while (tc--) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			sum[i] = sum[i - 1] + arr[i];
		}

		int ans = INT_MIN;
		for (int i = 1; i <= n; i++)
			for (int j = 0; j < i; j++)
				ans = max(ans, sum[i] - sum[j]);
		cout << ans << '\n';
	}

	return 0;
}