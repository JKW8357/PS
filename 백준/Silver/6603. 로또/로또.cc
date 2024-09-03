#include <bits/stdc++.h>
using namespace std;

int k;
int arr[15];
vector<int> vec;

void solve(int idx, int depth) {
	if (depth == 6) {
		for (int i : vec) cout << i << ' ';
		cout << '\n';
		return;
	}

	for (int i = idx; i < k; i++) {
		vec.push_back(arr[i]);
		solve(i + 1, depth + 1);
		vec.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (true) {
		cin >> k;
		if (k == 0) break;
		for (int i = 0; i < k; i++) cin >> arr[i];
		solve(0, 0);
		cout << '\n';
	}

	return 0;
}