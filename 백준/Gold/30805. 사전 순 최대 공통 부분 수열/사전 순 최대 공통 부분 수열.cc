#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

vector<pii> a;
vector<pii> b;
vector<int> ans;

bool cmp(const pii& a, const pii& b) {
	if (a.first != b.first) return a.first > b.first;
	return a.second < b.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		a.push_back({ num, i });
	}

	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		int num; cin >> num;
		b.push_back({ num, i });
	}

	sort(a.begin(), a.end(), cmp);
	sort(b.begin(), b.end(), cmp);
	
	int idx_a = 0, idx_b = 0;
	int lim_a = 0, lim_b = 0;

	while (idx_a < n && idx_b < m) {
		if (a[idx_a].first == b[idx_b].first) {
			if (lim_a > a[idx_a].second) idx_a++;
			else if (lim_b > b[idx_b].second) idx_b++;
			else {
				lim_a = a[idx_a].second;
				lim_b = b[idx_b].second;
				ans.push_back(a[idx_a].first);
				idx_a++;
				idx_b++;
			}
		}
		else if (a[idx_a].first > b[idx_b].first) idx_a++;
		else idx_b++;
	}

	cout << ans.size() << '\n';
	for (int e : ans) cout << e << ' ';

	return 0;
}