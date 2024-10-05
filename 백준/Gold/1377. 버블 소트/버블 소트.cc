#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v;
vector<int> idxDiff;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back({ num, i });
	}

	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) idxDiff.push_back({ v[i].second - i });
	int maxLeft = *max_element(idxDiff.begin(), idxDiff.end());
	cout << maxLeft + 1 << '\n';

	return 0;
}