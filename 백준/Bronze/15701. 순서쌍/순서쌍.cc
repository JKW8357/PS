#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> um;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			um[i]++;
			n /= i;
		}
	}
	if (n != 1) um[n]++;

	int ans = 1;
	if (!um.empty()) for (auto i : um) ans *= (i.second + 1);
	cout << ans << '\n';
	return 0;
}