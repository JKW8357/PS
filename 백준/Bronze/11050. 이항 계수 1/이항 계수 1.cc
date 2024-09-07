#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	int ans = 1, cnt = k;
	while (cnt--) ans *= n--;
	while (k) ans /= k--;
	
	cout << ans << '\n';
	return 0;
}