#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> row;
vector<int> col;

int maximum(vector<int>& v) {
	int offset = *min_element(v.begin(), v.end());
	for (int i = 0; i < n; i++) v[i] -= offset;
	
	vector<int> diff(*max_element(v.begin(), v.end()) + 1, 0);
	for (int i = 0; i < n; i++) {
		diff[min(v[i], v[(i - 1 + n) % n])]++;
		diff[max(v[i], v[(i - 1 + n) % n])]--;
	}

	for (int i = 1; i < (int)diff.size(); i++) diff[i] += diff[i - 1];
	return *max_element(diff.begin(), diff.end());
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	row.resize(n); col.resize(n);
	for (int i = 0; i < n; i++) cin >> row[i] >> col[i];
	int ans = max(maximum(row), maximum(col));
	cout << ans << '\n';

	return 0;
}