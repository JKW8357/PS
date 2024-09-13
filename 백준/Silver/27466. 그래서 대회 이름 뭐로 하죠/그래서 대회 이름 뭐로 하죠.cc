#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	string str;
	cin >> n >> m >> str;

	str.erase(str.find_last_not_of("AEIOU") + 1);

	int cntA = 0;
	string ans;
	if (!str.empty()) ans += str.back();
	int size = str.size();
	for (int i = size - 1; i >= 0; i--) {
		if (ans.size() == m) break;
		if (cntA == 2) ans += str[i];
		else if (str[i] == 'A') {
			cntA++;
			ans += 'A';
		}
	}

	if (cntA == 2 && ans.size() == m) {
		reverse(ans.begin(), ans.end());
		cout << "YES\n" << ans << '\n';
	}

	else cout << "NO\n";
	return 0;
}