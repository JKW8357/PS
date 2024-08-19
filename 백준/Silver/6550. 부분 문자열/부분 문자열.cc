#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s, t;
	while (cin >> s >> t) {
		int idx1 = 0, idx2 = 0;
		while (idx1 < s.size() && idx2 < t.size()) {
			if (s[idx1] == t[idx2]) idx1++;
			idx2++;
		}
		cout << (idx1 == s.size() ? "Yes" : "No") << '\n';
	}

	return 0;
}