#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str; cin >> str;
	char letter;

	while (cin >> letter) {
		for (char& c : str) {
			if (c == letter) c += 'a' - 'A';
		}
	}

	cout << str << '\n';
	return 0;
}