#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, ans;
	cin >> n >> m;

	if (n == 1) ans = 1;
	else if (n == 2) ans = min((m + 1) / 2, 4);
	else if (m < 7) ans = min(m, 4);
	else ans = m - 2;

	cout << ans << '\n';
	return 0;
}