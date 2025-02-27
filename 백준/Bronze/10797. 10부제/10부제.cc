#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n; cin >> n;
	int ans = 0;
	for (int i = 0; i < 5; i++) {
		int num; cin >> num;
		if (n == num) ans++;
	}
	cout << ans << '\n';

	return 0;
}