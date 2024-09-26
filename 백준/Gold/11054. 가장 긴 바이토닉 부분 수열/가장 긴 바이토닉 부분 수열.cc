#include <bits/stdc++.h>
using namespace std;

int arr[1005];
int dpGreater[1005];
int dpLess[1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dpGreater[i] = dpLess[i] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) dpGreater[i] = max(dpGreater[i], dpGreater[j] + 1);
			if (arr[n - 1 - i] > arr[n - 1 - j]) dpLess[n - 1 - i] = max(dpLess[n - 1 - i], dpLess[n - 1 - j] + 1);
		}
	}

	int ans = 1;
	for (int i = 0; i < n; i++) ans = max(ans, dpGreater[i] + dpLess[i] - 1);
	cout << ans << '\n';

	return 0;
}