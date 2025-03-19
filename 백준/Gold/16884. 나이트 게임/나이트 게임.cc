#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int tc; cin >> tc;
	while (tc--) {
		int n; cin >> n;
		cout << (n % 2 ? "koosaga" : "cubelover") << '\n';
	}
	
	return 0;
}