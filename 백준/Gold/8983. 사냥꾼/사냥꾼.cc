#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int n, m, l;
vector<int> hunter;
vector<pii> animals;

bool hunted(pii& animal) {
	auto& [a, b] = animal;
	int lo = 0, hi = hunter.size() - 1;

	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		int dist = abs(hunter[mid] - a) + b;
		if (dist <= l) return true;
		else if (hunter[mid] < a) lo = mid + 1;
		else hi = mid - 1;
	}

	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> m >> n >> l;
	hunter.resize(m);
	animals.resize(n);

	for (int i = 0; i < m; i++) cin >> hunter[i];
	for (int i = 0; i < n; i++) cin >> animals[i].first >> animals[i].second;
	sort(hunter.begin(), hunter.end());

	int cnt = 0;
	for (auto& animal : animals)
		if (hunted(animal)) cnt++;

	cout << cnt << '\n';
	return 0;
}