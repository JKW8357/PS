#include <bits/stdc++.h>
using namespace std;

string mirror[105];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> mirror[i];

	int cmd;
	cin >> cmd;

	if (cmd == 1) for (int i = 1; i <= n; i++) cout << mirror[i] << '\n';

	else if (cmd == 2) {
		for (int i = 1; i <= n; i++) {
			reverse(mirror[i].begin(), mirror[i].end());
			cout << mirror[i] << '\n';
		}
	}

	else for (int i = n; i >= 1; i--) cout << mirror[i] << '\n';

	return 0;
}