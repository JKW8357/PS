#include <bits/stdc++.h>
using namespace std;

int arr[300005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	
	long long ans = arr[n - 1];
	int l = 0, r = n - 2;
	while (k > 2) {
		ans += (arr[r--] - arr[l++]);
		k -= 2;
	}

	cout << ans << '\n';
	return 0;
}