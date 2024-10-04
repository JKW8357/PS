#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	cout << min({ a, b, c }) + min(d, e) - 50 << '\n';

	return 0;
}