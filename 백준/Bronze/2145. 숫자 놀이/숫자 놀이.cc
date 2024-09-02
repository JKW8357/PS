#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	while (true) {
		cin >> s;
		if (s == "0") break;
		while (s.size() != 1) {
			int sum = 0;
			for (int i = 0; i < (int)s.size(); i++) sum += s[i] - '0';
			s = to_string(sum);
		}
		cout << s << '\n';
	}

	return 0;
}