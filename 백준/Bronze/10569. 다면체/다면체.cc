#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tc;
	cin >> tc;

	while (tc--) {
		int v, e;
		cin >> v >> e;
		cout << e - v + 2 << '\n';
	}

	return 0;
}