#include <bits/stdc++.h>
using namespace std;

set<string> items;
unordered_map<string, vector<string>> adj;
unordered_map<string, int> ind;

void topologicalSort() {
	vector<string> result;
	priority_queue<string, vector<string>, greater<string>> curPQ;
	priority_queue<string, vector<string>, greater<string>> nextPQ;

	for (auto& item : items)
		if (ind[item] == 0) curPQ.push(item);

	while (!curPQ.empty()) {
		while (!curPQ.empty()) {
			string cur = curPQ.top(); curPQ.pop();
			result.push_back(cur);
			for (auto& nxt : adj[cur])
				if (--ind[nxt] == 0) nextPQ.push(nxt);
		}
		curPQ = move(nextPQ);
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