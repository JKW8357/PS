#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (true) {
		string str;
		cin >> str;
		if (str == "#") break;

		int cnt = 0;
		for (int i = 0; i < str.size() - 1; i++) {
			if (str[i] == '1') cnt++;
			cout << str[i];
		}

		if (str[str.size() - 1] == 'o') cout << (cnt % 2 == 1 ? '0' : '1');
		else cout << (cnt % 2 == 1 ? '1' : '0');
		cout << '\n';
	}

	return 0;
}