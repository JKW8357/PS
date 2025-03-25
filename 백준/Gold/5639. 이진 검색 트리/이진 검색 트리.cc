#include <bits/stdc++.h>
using namespace std;

vector<int> preOrder;

void postOrder(int start, int end) {
	if (start > end) return;

	int root = preOrder[start];
	int idx = lower_bound(preOrder.begin() + start + 1, preOrder.end(), root) - preOrder.begin();

	postOrder(start + 1, idx - 1);
	postOrder(idx, end);

	cout << root << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int val;
	while (cin >> val) preOrder.push_back(val);
	postOrder(0, (int)preOrder.size() - 1);

	return 0;
}