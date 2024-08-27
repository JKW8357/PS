#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 1; i <= k; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ (a - 1) + (m + 1 - b), i});
	}

	sort(v.begin(), v.end());
	cout << v[0].second << '\n';
	return 0;
}