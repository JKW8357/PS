#include <bits/stdc++.h>
using namespace std;

int n;
int ans = INT_MAX;
vector<pair<int, int>> ingredients;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int s, b;
		cin >> s >> b;
		ingredients.push_back({ s, b });
	}

	for (int mask = 1; mask < (1 << n); mask++) {
		int sour = 1;
		int bitter = 0;

		for (int i = 0; i < n; i++) {
			if (mask & (1 << i)) {
				sour *= ingredients[i].first;
				bitter += ingredients[i].second;
			}
		}

		ans = min(ans, abs(sour - bitter));
	}
	
	cout << ans << '\n';
	return 0;
}