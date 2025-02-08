#include <bits/stdc++.h>
using namespace std;

set<string> items;
unordered_map<string, vector<string>> adj;
unordered_map<string, int> ind;

void topologicalSort() {
	queue<string> q;
	vector<string> result;

	for (auto& item : items)
		if (ind[item] == 0) q.push(item);

	set<string> tmp;
	while (!q.empty()) {
		while (!q.empty()) {
			string cur = q.front(); q.pop();
			result.push_back(cur);
			for (auto& nxt : adj[cur])
				if (--ind[nxt] == 0) tmp.insert(nxt);
		} 

		while (!tmp.empty()) {
			q.push(*tmp.begin());
			tmp.erase(tmp.begin());
		}
	}

	if (result.size() != items.size()) cout << -1 << '\n';
	else for (auto& e : result) cout << e << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	while (n--) {
		string item1, item2;
		cin >> item1 >> item2;

		items.insert(item1);
		items.insert(item2);

		adj[item1].push_back(item2);
		ind[item2]++;
	}

	topologicalSort();
	return 0;
}