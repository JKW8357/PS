#include <bits/stdc++.h>
using namespace std;

vector<int> score(100005);
vector<int> p(100005);
vector<int> adj[100005];

void dfs(int cur) {
	if (p[cur] != -1) score[cur] += score[p[cur]];
	for (int nxt : adj[cur]) dfs(nxt);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		if (p[i] == -1) continue;
		adj[p[i]].push_back(i);
	}

	while (m--) {
		int i, w;
		cin >> i >> w;
		score[i] += w;
	}
	
	dfs(1);
	for (int i = 1; i <= n; i++)  cout << score[i] << ' ';

	return 0;
}