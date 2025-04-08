#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string s; cin >> s;
	int ans = 10;
	for (int i = 1; i < (int)s.size(); i++)
		ans += (s[i] == s[i - 1] ? 5 : 10);
	cout << ans << '\n';

	return 0;
}