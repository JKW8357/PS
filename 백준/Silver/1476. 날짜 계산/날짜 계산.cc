#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int e, s, m;
	cin >> e >> s >> m;
	int i = e;
	while (i % 28 != (s == 28 ? 0 : s)) i += 15;
	while (i % 19 != (m == 19 ? 0 : m)) i += 420;
	cout << i << '\n';
}