#include <bits/stdc++.h>
using namespace std;

int arr[1000005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;
	while (n--) {
		int g, x;
		cin >> g >> x;
		arr[x] = g;
	}

	int sum = 0;
	for (int i = 0; i <= 2 * k && i <= 1000000; i++) sum += arr[i];

	int curSum = sum, maxSum = sum;
	int l = 0, r = 2 * k + 1;
	while (r <= 1000000) {
		curSum -= arr[l++];
		curSum += arr[r++];
		maxSum = max(maxSum, curSum);
	}
	cout << maxSum << '\n';

	return 0;
}