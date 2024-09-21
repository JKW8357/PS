#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int n; cin >> n;

	cout << "? " << 1 << endl;
	int st; cin >> st;

	cout << "? " << n << endl;
	int en; cin >> en;

	cout << "! ";
	if (st < en) cout << 1 << endl;
	else if (st == en) cout << 0 << endl;
	else cout << -1 << endl;

	return 0;
}