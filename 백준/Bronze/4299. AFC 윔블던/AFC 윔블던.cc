#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int sum, sub;
	cin >> sum >> sub;

	int a = (sum + sub) / 2;
	int b = (sum - sub) / 2;

	if (sum < sub || (a + b != sum) || a - b != sub) cout << -1 << '\n';
	else cout << a << ' ' << b << '\n';

	return 0;
}