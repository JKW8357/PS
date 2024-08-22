#include <bits/stdc++.h>
using namespace std;

vector<pair<double, int>> vec;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		double x, y, v;
		cin >> x >> y >> v;
		vec.push_back({ hypot(x, y) / v, i });
	}
	sort(vec.begin(), vec.end());
	for (auto i : vec) cout << i.second << '\n';

	return 0;
}