#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	string ans(n - k + 1, 'a');
	for (int i = 0; i < k - 1; i++) ans += 'b' + i;
	cout << ans << '\n';

	return 0;
}