#include <bits/stdc++.h>
using namespace std;

int arr[10005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);

	long long cnt = 0;
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			int* left = lower_bound(arr + j + 1, arr + n, -(arr[i] + arr[j]));
			int* right = upper_bound(arr + j + 1, arr + n, -(arr[i] + arr[j]));
			if (left != right)
				cnt += right - left;
		}
	}

	cout << cnt << '\n';
	return 0;
}