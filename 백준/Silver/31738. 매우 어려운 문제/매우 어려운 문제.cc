#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, m;
	cin >> n >> m;

	ll mod = 0;
	if (n < m) {
		mod = 1;
		for (int i = 1; i <= n; i++) {
			mod = (mod * i) % m;
			if (mod == 0) break;
		}
	}

	cout << mod << '\n';
	return 0;
}