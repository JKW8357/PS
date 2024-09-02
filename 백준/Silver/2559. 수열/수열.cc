#include <bits/stdc++.h>
using namespace std;

int arr[100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> arr[i];

	int sum = accumulate(arr, arr + k, 0);
	int max_val = sum;
	for (int i = 1; i <= n - k; i++) {
		sum += arr[i + k - 1] - arr[i - 1];
		max_val = max(max_val, sum);
	}

	cout << max_val << '\n';
	return 0;
}