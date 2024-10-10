#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int st, en;
		cin >> st >> en;
		v.push_back({ st, en });
	}

	sort(v.begin(), v.end());

	pq.push(v[0].second);
	for (int i = 1; i < n; i++) {
		if (v[i].first >= pq.top()) pq.pop();
		pq.push(v[i].second);
	}

	cout << pq.size() << '\n';
	return 0;
}