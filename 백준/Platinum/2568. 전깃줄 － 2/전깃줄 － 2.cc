#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

set<int> LIS(const vector<int>& vec) {
	int size = (int)vec.size();
	vector<int> tmp, idx(size);

	for (int i = 0; i < size; i++) {
		int pos = lower_bound(tmp.begin(), tmp.end(), vec[i]) - tmp.begin();
		if (pos == (int)tmp.size()) tmp.push_back(vec[i]);
		else tmp[pos] = vec[i];
		idx[i] = pos;
	}

	set<int> res;
	int len = (int)tmp.size();
	for (int i = size - 1; i >= 0; i--) {
		if (idx[i] == len - 1) {
			res.insert(vec[i]);
			len--;
		}
	}

	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	vector<pii> wires(n);
	for (int i = 0; i < n; i++) cin >> wires[i].first >> wires[i].second;
	sort(wires.begin(), wires.end());

	vector<int> vec;
	for (auto& [a, b] : wires) vec.push_back(b);

	set<int> lis = LIS(vec);
	vector<int> ans;
	for (auto& [a, b] : wires)
		if (!lis.count(b)) ans.push_back(a);

	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (int a : ans) cout << a << '\n';

	return 0;
}