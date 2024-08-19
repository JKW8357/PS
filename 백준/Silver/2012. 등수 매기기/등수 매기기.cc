#include <bits/stdc++.h>
using namespace std;

int arr[500005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> arr[i];
	sort(arr + 1, arr + n + 1);

	long long ans = 0;
	for (int i = 1; i <= n; i++) ans += abs(arr[i] - i);
	cout << ans << '\n';

	return 0;
}