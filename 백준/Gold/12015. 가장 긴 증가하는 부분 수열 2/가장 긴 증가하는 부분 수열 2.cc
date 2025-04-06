#include <bits/stdc++.h>
using namespace std;

vector<int> vec, tmp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vec.resize(n);
	for (int i = 0; i < n; i++) cin >> vec[i];

	int len = 0;
	for (int num : vec) {
		auto pos = lower_bound(tmp.begin(), tmp.end(), num);
		if (pos == tmp.end()) {
			tmp.push_back(num);
			len++;
		}
		else *pos = num;
	}

	cout << len << '\n';
	return 0;
}