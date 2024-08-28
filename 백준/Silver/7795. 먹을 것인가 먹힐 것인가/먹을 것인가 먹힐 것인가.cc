#include <bits/stdc++.h>
using namespace std;

int a[20005];
int b[20005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tc;
	cin >> tc;

	while (tc--) {
		int n, m;
		cin >> n >> m;

		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < m; i++) cin >> b[i];

		sort(b, b + m);

		int ans = 0;
		for (int i = 0; i < n; i++)
			ans += lower_bound(b, b + m, a[i]) - b;

		cout << ans << '\n';
	}

	return 0;
}