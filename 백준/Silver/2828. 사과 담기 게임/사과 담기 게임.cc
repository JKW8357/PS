#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, j;
	cin >> n >> m >> j;

	int left = 1, right = m, ans = 0;
	while (j--) {
		int num;
		cin >> num;
		if (num >= left && num <= right) continue;
		else if (num < left) {
			ans += left - num;
			right -= left - num;
			left = num;
		}
		else {
			ans += num - right;
			left += num - right;
			right = num;
		}
	}

	cout << ans;

	return 0;
}