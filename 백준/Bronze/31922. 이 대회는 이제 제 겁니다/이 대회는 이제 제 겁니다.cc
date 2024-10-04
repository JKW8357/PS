#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, p, c;
	cin >> a >> p >> c;
	cout << max(a + c, p) << '\n';

	return 0;
}