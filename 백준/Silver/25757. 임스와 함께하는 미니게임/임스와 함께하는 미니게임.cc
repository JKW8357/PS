#include <bits/stdc++.h>
using namespace std;

unordered_map<string, bool> um;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, required;
	char y;
	cin >> n >> y;
	if (y == 'Y') required = 2;
	else if (y == 'F') required = 3;
	else required = 4;

	int members = 1, playcnt = 0;
	while (n--) {
		string name;
		cin >> name;

		if (!um[name]) {
			um[name] = true;
			members++;
			if (members == required) {
				playcnt++;
				members = 1;
			}
		}
	}

	cout << playcnt << '\n';
	return 0;
}