#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	for (int i = n / 2; i >= 1; i--)
		cout << i << ' ' << i + n / 2 << ' ';
	if (n % 2) cout << n << '\n';

	return 0;
}