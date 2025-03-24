#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string s;
	while (getline(cin, s)) {
		for (char c : s) {
			if (c == 'e') cout << 'i';
			else if (c == 'E') cout << 'I';
			else if (c == 'i') cout << 'e';
			else if (c == 'I') cout << 'E';
			else cout << c;
		}
		cout << '\n';
	}

	return 0;
}