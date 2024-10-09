#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	
	long long ans = 1;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		ans *= num % m;
		ans %= m;
	}

	cout << ans << '\n';
	return 0;
}