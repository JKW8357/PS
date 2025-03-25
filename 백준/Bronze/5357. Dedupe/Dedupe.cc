#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	while (n--) {
		string s; cin >> s;
		cout << s[0];
		for (int i = 1; i < (int)s.size(); i++) {
			if (s[i] == s[i - 1]) continue;
			cout << s[i];
		}
		cout << '\n';
	}

	return 0;
}