#include <bits/stdc++.h>
using namespace std;

int arr[100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);

	int l = 0, r = n - 1;
	int minVal = INT_MAX;
	int ans1, ans2;
	while (minVal != 0 && l < r) {
		int sum = arr[l] + arr[r];
		if (minVal > abs(sum)) {
			minVal = min(minVal, abs(sum));
			ans1 = arr[l];
			ans2 = arr[r];
		}
		sum > 0 ? r-- : l++;
	}
	cout << ans1 << ' ' << ans2;

	return 0;
}