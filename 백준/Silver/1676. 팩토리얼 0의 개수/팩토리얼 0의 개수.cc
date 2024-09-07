#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int ans = 0;
	while (n != 0) {
		ans += n / 5;
		n /= 5;
	}

	cout << ans << '\n';
	return 0;
}