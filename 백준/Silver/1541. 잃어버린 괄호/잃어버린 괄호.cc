#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str; cin >> str;
	bool isMinus = false;
	int ans = 0, num = 0;
	string tmp;

	for (int i = 0; i <= str.size(); i++) {
		if (i == str.size() || !isdigit(str[i])) {
			num = stoi(tmp);
			ans += isMinus ? -num : num;
			tmp.clear();
			num = 0;
		}
		else if (isdigit(str[i])) tmp += str[i];
		if (str[i] == '-') isMinus = true;
	}

	cout << ans << '\n';
	return 0;
}