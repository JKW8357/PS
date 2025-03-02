#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int k, n;
	cin >> k >> n;

	for (int i = 1; i < n; i++) {
		cout << i << "\n";
		k -= i;
	}
	cout << k << '\n';

	return 0;
}