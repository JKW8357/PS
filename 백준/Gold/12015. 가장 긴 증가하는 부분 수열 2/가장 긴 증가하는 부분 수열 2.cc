#include <bits/stdc++.h>
using namespace std;

vector<int> vec;
vector<int> ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		vec.push_back(num);
	}

	for (int num : vec) {
		auto pos = lower_bound(ans.begin(), ans.end(), num);
		if (pos == ans.end()) ans.push_back(num);
		else *pos = num;
	}

	cout << ans.size() << '\n';
	return 0;
}