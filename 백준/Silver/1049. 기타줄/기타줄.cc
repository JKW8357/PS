#include <bits/stdc++.h>
using namespace std;

int package[55];
int single[55];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
		cin >> package[i] >> single[i];

	int p = *min_element(package, package + m);
	int s = *min_element(single, single + m);

	int ans = n / 6 * min(s * 6, p) + min(n % 6 * s, p);
	cout << ans;

	return 0;
}