#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

vector<pii> v;

bool cmp(pii p1, pii p2) {
	if (p1.second != p2.second) return p1.second < p2.second;
	return p1.first < p2.first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({ x,y });
	}

	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < n; i++)
		cout << v[i].first << ' ' << v[i].second << '\n';

	return 0;
}