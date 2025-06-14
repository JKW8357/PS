#include <bits/stdc++.h>
using namespace std;

vector<int> LIS(const vector<int>& vec) {
	int size = (int)vec.size();
	vector<int> tmp, idx(size), res;

	for (int i = 0; i < size; i++) {
		int pos = lower_bound(tmp.begin(), tmp.end(), vec[i]) - tmp.begin();
		if (pos == (int)tmp.size()) tmp.push_back(vec[i]);
		else tmp[pos] = vec[i];
		idx[i] = pos;
	}

	int len = (int)tmp.size();
	for (int i = size - 1; i >= 0; i--) {
		if (idx[i] == len - 1) {
			res.push_back(vec[i]);
			len--;
		}
	}
	reverse(res.begin(), res.end());

	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	map<int, int> arr, rev;
	set<int> s;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		arr[a] = b;
		rev[b] = a;
		s.insert(b);
	}

	vector<int> vec;
	for (auto& [idx, val] : arr) vec.push_back(val);

	vector<int> lis = LIS(vec);
	set<int> ans;

	for (int b : lis) s.erase(b);
	for (int b : s) ans.insert(rev[b]);

	cout << ans.size() << '\n';
	for (int a : ans) cout << a << '\n';

	return 0;
}