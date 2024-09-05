#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string ans = "";
	while (true) {
		string str;
		getline(cin, str);
		if (str == "END") break;
		reverse(str.begin(), str.end());
		ans += str + '\n';
	}

	cout << ans << '\n';
	return 0;
}