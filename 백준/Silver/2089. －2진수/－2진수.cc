#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	string ans;

	if (n == 0) {
		cout << '0' << '\n';
		return 0;
	}

	while (n != 0) {
		int r = abs(n) % 2;
		ans += to_string(r);
		n = (n - r) / (-2);
	}

	reverse(ans.begin(), ans.end());
	cout << ans << '\n';
	return 0;
}