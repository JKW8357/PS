#include <bits/stdc++.h>
using namespace std;

int arr[10005];
int narr[10005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;

		for (int i = 0; i < n; i++) cin >> arr[i];
		sort(arr, arr + n);

		int left = 0, right = n - 1;
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) narr[left++] = arr[i];
			else narr[right--] = arr[i];
		}

		int ans = 0;
		for (int i = 0; i < n - 1; i++) ans = max(ans, abs(narr[i + 1] - narr[i]));
		cout << ans << '\n';
	}

	return 0;
}