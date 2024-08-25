#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	while (m--) {
		int a, b;
		cin >> a >> b;
		int l = lower_bound(v.begin(), v.end(), a) - v.begin();
		int r = upper_bound(v.begin(), v.end(), b) - v.begin();
		cout << r - l << '\n';
	}

	return 0;
}