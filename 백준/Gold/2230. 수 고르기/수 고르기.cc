#include <bits/stdc++.h>
using namespace std;

int arr[100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	
	int ans = INT_MAX;
	int st = 0, en = 0;
	while (st < n) {
		while (en < n && arr[en] - arr[st] < m) en++;
		if (en == n) break;
		ans = min(ans, arr[en] - arr[st++]);
	}
	
	cout << ans << '\n';
	return 0;
}