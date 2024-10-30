#include <bits/stdc++.h>
using namespace std;

int arr[500005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);

	int m; cin >> m;
	while (m--) {
		int num; cin >> num;
		int cnt = upper_bound(arr, arr + n, num) - lower_bound(arr, arr + n, num);
		cout << cnt << ' ';
	}

	return 0;
}