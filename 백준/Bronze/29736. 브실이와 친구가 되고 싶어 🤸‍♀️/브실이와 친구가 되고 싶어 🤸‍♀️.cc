#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, k, x;
	cin >> a >> b >> k >> x;

	int _min = k - x;
	int _max = k + x;

	if (_min > b || _max < a) cout << "IMPOSSIBLE\n";
	else cout << min(_max, b) - max(_min, a) + 1 << '\n';

	return 0;
}