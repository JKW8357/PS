#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> vec;

void solve(int depth) {
	if (depth == m) {
		for (int i = 0; i < m; i++) cout << vec[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		vec.push_back(i);
		solve(depth + 1);
		vec.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	solve(0);

	return 0;
}