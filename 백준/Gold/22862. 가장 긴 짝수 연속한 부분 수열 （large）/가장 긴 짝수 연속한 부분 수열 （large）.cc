#include <bits/stdc++.h>
using namespace std;

int arr[1000005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> arr[i];

	int odds = 0;
	int maxLength = 0;
	int l = 0, r = 0;

	while (r < n) {
		if (arr[r] % 2 != 0) odds++;

		while (odds > k) {
			if (arr[l] % 2 != 0) odds--;
			l++;
		}

		maxLength = max(maxLength, r - l + 1 - odds);
		r++;
	}

	cout << maxLength << '\n';
	return 0;
}