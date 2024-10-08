#include <bits/stdc++.h>
using namespace std;

int n, k;
int cnt = 0;
int num[3] = { 1, 2, 3 };
vector<int> vec;

void solve(int depth, int sum) {
	if (sum > n) return;

	else if (sum == n) {
		if (++cnt == k) {
			for (int i = 0; i < depth - 1; i++) cout << vec[i] << '+';
			cout << vec[depth - 1];
		}
		return;
	}
	
	for (int i = 1; i <= 3; i++) {
		vec.push_back(i);
		solve(depth + 1, sum + i);
		vec.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	solve(0, 0);
	if (cnt < k) cout << -1 << '\n';

	return 0;
}