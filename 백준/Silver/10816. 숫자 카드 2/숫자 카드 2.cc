#include <bits/stdc++.h>
using namespace std;

int arr[500005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);

	int m;
	cin >> m;
	while(m--) {
		int q;
		cin >> q;
		cout << upper_bound(arr, arr + n, q) - lower_bound(arr, arr + n, q) << ' ';
	}

	return 0;
}