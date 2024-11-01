#include <bits/stdc++.h>
using namespace std;

int arr[20];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 0; i < n; i++) cin >> arr[i];
		cout << 2 * (*max_element(arr, arr + n) - *min_element(arr, arr + n)) << '\n';
	}

	return 0;
}