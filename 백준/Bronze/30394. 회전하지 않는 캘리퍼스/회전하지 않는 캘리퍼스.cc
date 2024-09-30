#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int maxY = INT_MIN;
	int minY = INT_MAX;
	int ans = 0;
	while (n--) {
		int x, y;
		cin >> x >> y;
		maxY = max(maxY, y);
		minY = min(minY, y);
		ans = max(ans, maxY - minY);
	}

	cout << ans << '\n';
	return 0;
}