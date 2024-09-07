#include <bits/stdc++.h>
using namespace std;

int arr[105];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tc;
	cin >> tc;

	while (tc--) {
		int n;
		cin >> n;
		long long ans = 0;
		for (int i = 0; i < n; i++) cin >> arr[i];
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				ans += gcd(arr[i], arr[j]);
		cout << ans << '\n';
	}

	return 0;
}