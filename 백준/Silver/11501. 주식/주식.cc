#include <bits/stdc++.h>
using namespace std;

long long arr[1000005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tc;
	cin >> tc;

	while (tc--) {
		int n;
		cin >> n;

		for (int i = 0; i < n; i++) cin >> arr[i];

		long long ans = 0, tmp = arr[n - 1];
		for (int i = n - 1; i > 0; i--) {
			if (tmp >= arr[i - 1]) ans += tmp - arr[i - 1];
			else tmp = arr[i - 1];
		}

		cout << ans << '\n';
	}

	return 0;
}