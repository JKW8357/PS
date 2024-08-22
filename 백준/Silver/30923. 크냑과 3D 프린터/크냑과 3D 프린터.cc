#include <bits/stdc++.h>
using namespace std;

int arr[33000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		if (i == n) ans += arr[n];
		ans += (abs(arr[i] - arr[i - 1]) + 2 * (arr[i] + 1));
	}

	cout << ans << '\n';
	return 0;
}