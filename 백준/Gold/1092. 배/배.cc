#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<int> cranes(n);
	for (int i = 0; i < n; i++) cin >> cranes[i];
	sort(cranes.begin(), cranes.end());

	int m; cin >> m;
	vector<int> boxes(m);
	for (int i = 0; i < m; i++) cin >> boxes[i];
	sort(boxes.begin(), boxes.end());

	if (cranes.back() < boxes.back()) {
		cout << -1 << '\n';
		return 0;
	}

	vector<int> used(n);
	for (int i = (int)boxes.size() - 1; i >= 0; --i) {
		auto it = lower_bound(cranes.begin(), cranes.end(), boxes[i]);
		if (it == cranes.end()) continue;
		int init = it - cranes.begin();

		int cand = min_element(used.begin() + init, used.end()) - used.begin();
		used[cand]++;
	}

	cout << *max_element(used.begin(), used.end()) << '\n';
	return 0;
}