#include <bits/stdc++.h>
using namespace std;

int arr[1005];
int dp[1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) cin >> arr[i];
	fill(dp, dp + n, 1);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++)
			if (arr[i] > arr[j]) dp[i] = max(dp[i], dp[j] + 1);

	int max_idx = max_element(dp, dp + n) - dp;
	int idx = max_idx;

	vector<int> vec = { arr[max_idx]};
	while (--idx >= 0) {
		if (dp[max_idx] - 1 == dp[idx]) {
			vec.push_back(arr[idx]);
			max_idx = idx;
		}
	}

	cout << *max_element(dp, dp + n) << '\n';
	for (int i = vec.size() - 1; i >= 0; i--) cout << vec[i] << ' ';

	return 0;
}