#include <bits/stdc++.h>
using namespace std;

int k;
int arr[1030];
vector<int> tree[12];

void solve(int st, int en, int level) {
	if (st > en) return;

	int rootIdx = (st + en) / 2;
	tree[level].push_back(arr[rootIdx]);

	solve(st, rootIdx - 1, level + 1);
	solve(rootIdx + 1, en, level + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> k;
	for (int i = 0; i < (1 << k) - 1; i++) cin >> arr[i];
	solve(0, (1 << k) - 1, 0);
	for (int level = 0; level < k; level++) {
		for (int x : tree[level]) cout << x << ' ';
		cout << '\n';
	}

	return 0;
}