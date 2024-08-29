#include <bits/stdc++.h>
using namespace std;

deque<int> dq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		dq.push_back(num);
	}

	for (int i = 0; i < n - 1; i++) {
		dq.push_back(dq[1] - dq[0]);
		dq.pop_front();
	}

	dq.pop_front();
	sort(dq.begin(), dq.end());
	cout << accumulate(dq.begin(), dq.begin() + (n - k), 0) << '\n';

	return 0;
}