#include <bits/stdc++.h>
using namespace std;

vector<int> LIS(const vector<int>& vec) {
	int size = (int)vec.size();
	vector<int> tmp, idx(size), result;

	for (int i = 0; i < size; i++) {
		int pos = lower_bound(tmp.begin(), tmp.end(), vec[i]) - tmp.begin();
		if (pos == tmp.size()) tmp.push_back(vec[i]);
		else tmp[pos] = vec[i];
		idx[i] = pos;
	}

	int len = (int)tmp.size();
	cout << len << '\n';
	for (int i = size - 1; i >= 0; i--) {
		if (idx[i] == len - 1) {
			result.push_back(vec[i]);
			len--;
		}
	}
	reverse(result.begin(), result.end());

	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<int> vec(n);
	for (int i = 0; i < n; i++) cin >> vec[i];

	vector<int> lis = LIS(vec);
	for (int x : lis) cout << x << ' ';

	return 0;
}