#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string a, b;
	cin >> a >> b;

	int ans = INT_MAX;
	int diff = b.size() - a.size();
	for (int i = 0; i <= diff; i++) {
		int cnt = 0;
		for (int j = 0; j < a.size(); j++)
			if (a[j] != b[j + i]) cnt++;
		ans = min(ans, cnt);
	}

	cout << ans << '\n';
	return 0;
}