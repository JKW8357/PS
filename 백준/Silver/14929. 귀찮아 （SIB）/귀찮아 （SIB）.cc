#include <bits/stdc++.h>
using namespace std;

int arr[100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	int sum = accumulate(arr + 1, arr + n + 1, 0);

	long long ans = 0;
	for (int i = 1; i <= n - 1; i++) {
		sum -= arr[i];
		ans += arr[i] * sum;
	}
	cout << ans << '\n';

	return 0;
}