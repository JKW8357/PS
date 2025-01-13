#include <bits/stdc++.h>
using namespace std;

int arr[100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	int l = 0, r = n - 1;
	int s1, s2;
	int ans = 2 * int(1e9) + 1;

	while (l < r) {
		int diff = arr[l] + arr[r];
		if (ans > abs(diff)) {
			ans = abs(diff);
			s1 = arr[l];
			s2 = arr[r];
		}
		else diff > 0 ? r-- : l++;
	}

	cout << s1 << ' ' << s2 << '\n';
	return 0;
}