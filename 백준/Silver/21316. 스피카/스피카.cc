#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj(13);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (int i = 0; i < 12; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int cur = 1; cur <= 12; cur++) {
		if (adj[cur].size() == 3) {
			int nxtEdgesCount = 0;
			for (int nxt : adj[cur])
				nxtEdgesCount += (int)adj[nxt].size();
			if (nxtEdgesCount == 6) {
				cout << cur << '\n';
				break;
			}
		}
	}

	return 0;
}