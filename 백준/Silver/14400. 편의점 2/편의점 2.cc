#include <bits/stdc++.h>
using namespace std;

int x[100005];
int y[100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> x[i] >> y[i];

	sort(x, x + n);
	sort(y, y + n);

	int midx = x[(n - 1) / 2];
	int midy = y[(n - 1) / 2];

	long long ans = 0;
	for (int i = 0; i < n; i++) ans += abs(midx - x[i]) + abs(midy - y[i]);
	cout << ans << '\n';
	
	return 0;
}