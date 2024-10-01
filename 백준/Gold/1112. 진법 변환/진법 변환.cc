#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int x, b;
	cin >> x >> b;
	string ans;

	if (x == 0) {
		cout << '0' << '\n';
		return 0;
	}

	int tmp = x;
	if (x < 0 && b > 0) tmp = abs(x);
	while (tmp != 0) {
		int r = tmp % b;
		if (r < 0) r += abs(b);
		tmp = (tmp - r) / b;
		ans += to_string(r);
	}

	if (x < 0 && b > 0) ans += "-";
	reverse(ans.begin(), ans.end());
	cout << ans << '\n';
	return 0;
}