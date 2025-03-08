#include <bits/stdc++.h>
using namespace std;

int arr[100005];
int sum[100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		sum[i] = arr[i] + sum[i - 1];
	}

	int ans = 0;
	for (int i = 2; i <= n - 1; i++) {
		ans = max(ans, sum[n] - sum[1] + sum[n] - sum[i] - arr[i]);
		ans = max(ans, sum[n - 1] + sum[i - 1] - arr[i]);
		ans = max(ans, sum[n - 1] - sum[1] + arr[i]);
	}

	cout << ans << '\n';	
	return 0;
}