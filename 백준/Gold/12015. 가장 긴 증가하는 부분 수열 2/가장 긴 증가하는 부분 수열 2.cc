#include <bits/stdc++.h>
using namespace std;

vector<int> vec;
vector<int> tmp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vec.resize(n);
	for (int i = 0; i < n; i++) cin >> vec[i];

	for (int num : vec) {
		auto pos = lower_bound(tmp.begin(), tmp.end(), num);
		if (pos == tmp.end()) tmp.push_back(num);
		else *pos = num;
	}

	cout << tmp.size() << '\n';
	return 0;
}