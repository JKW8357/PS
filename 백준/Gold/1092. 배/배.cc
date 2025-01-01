#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> cranes;
vector<int> weights;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n; cranes.resize(n);
	for (int i = 0; i < n; i++) cin >> cranes[i];
	sort(cranes.begin(), cranes.end(), greater<int>());

	cin >> m; weights.resize(m);
	for (int i = 0; i < m; i++) cin >> weights[i];
	sort(weights.begin(), weights.end(), greater<int>());

	if (weights[0] > cranes[0]) {
		cout << -1 << '\n';
		return 0;
	}

	int times = 0;
	while (!weights.empty()) {
		int idx = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < weights.size(); j++) {
				if (cranes[i] >= weights[j]) {
					weights.erase(weights.begin() + j);
					break;
				}
			}
		}

		times++;
	}

	cout << times << '\n';
	return 0;
}