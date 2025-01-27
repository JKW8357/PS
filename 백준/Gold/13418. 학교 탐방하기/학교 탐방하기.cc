#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<tuple<int, int, int>> adj;
vector<int> p;

int find(int x) {
	if (p[x] == -1) return x;
	return p[x] = find(p[x]);
}

bool unite(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return false;
	p[y] = x;
	return true;
}

int calc() {
	p.assign(n + 1, -1);
	int cnt = 0, sum = 0;
	for (auto& [c, a, b] : adj) {
		if (!unite(a, b)) continue;
		sum += c;
		cnt++;
		if (cnt == n - 1) break;
	}
	return sum * sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	n++; m++;
	while(m--) {
		int a, b, c;
		cin >> a >> b >> c;
		adj.push_back({ 1 - c, a, b });
	}

	sort(adj.rbegin(), adj.rend());
	int maxVal = calc();

	sort(adj.begin(), adj.end());
	int minVal = calc();

	int ans = maxVal - minVal;
	cout << ans << '\n';

	return 0;
}