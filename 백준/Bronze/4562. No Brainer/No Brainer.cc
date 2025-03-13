#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	while (n--) {
		int x, y;
		cin >> x >> y;
		if (x >= y) cout << "MMM BRAINS\n";
		else cout << "NO BRAINS\n";
	}

	return 0;
}