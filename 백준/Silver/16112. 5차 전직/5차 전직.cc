#include <bits/stdc++.h>
using namespace std;

long long stone[300005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) cin >> stone[i];
	sort(stone, stone + n);

	int activated = 0;
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		ans += stone[i] * activated;
		if (activated < k) activated++;
	}
	cout << ans << '\n';

	return 0;
}