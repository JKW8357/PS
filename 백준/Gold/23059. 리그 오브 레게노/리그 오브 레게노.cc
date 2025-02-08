#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> ind;
vector<string> names;
unordered_map<string, int> id;
set<string> items;
vector<pair<string, string>> edges;

void topologicalSort() {
	queue<int> q;
	vector<int> result;

	for (int i = 0; i < (int)names.size(); i++)
		if (ind[i] == 0) q.push(i);

	set<int> tmp;
	while (!q.empty()) {
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			result.push_back(cur);
			for (auto nxt : adj[cur])
				if (--ind[nxt] == 0) tmp.insert(nxt);
		}
		
		while (!tmp.empty()) {
			q.push(*tmp.begin());
			tmp.erase(tmp.begin());
		}
	}

	if (result.size() != names.size()) cout << -1 << '\n';
	else for (auto e : result) cout << names[e] << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	while (n--) {
		string a, b;
		cin >> a >> b;
		edges.push_back({ a, b });
		items.insert(a);
		items.insert(b);
	}

	for (const auto& s : items) names.push_back(s);
	for (int i = 0; i < (int)names.size(); i++)	id[names[i]] = i;

	adj.assign(names.size(), vector<int>());
	ind.assign(names.size(), 0);

	for (auto& [a, b] : edges) {
		adj[id[a]].push_back(id[b]);
		ind[id[b]]++;
	}

	topologicalSort();
	return 0;
}