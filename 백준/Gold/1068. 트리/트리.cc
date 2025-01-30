#include <bits/stdc++.h>
using namespace std;

int rootNode;
int deletedNode;
vector<int> c[55];

int dfs(int cur) {
	if (cur == deletedNode) return 0;
	if (c[cur].empty()) return 1;
	if (c[cur].size() == 1 && c[cur][0] == deletedNode) return 1;

	int result = 0;
	for (int nxt : c[cur]) result += dfs(nxt);
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int p; cin >> p;
		if (p == -1) rootNode = i;
		else c[p].push_back(i);
	}
	cin >> deletedNode;

	int ans = dfs(rootNode);
	cout << ans << '\n';

	return 0;
}