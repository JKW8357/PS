#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int tc; cin >> tc;
	while (tc--) {
		priority_queue<int> maxHeap;
		priority_queue<int, vector<int>, greater<int>> minHeap;
		vector<int> medians;

		int m; cin >> m;
		for (int i = 1; i <= m; i++) {
			int num; cin >> num;
			if (i % 2 == 1) maxHeap.push(num);
			else minHeap.push(num);

			if (!maxHeap.empty() && !minHeap.empty() && maxHeap.top() > minHeap.top()) {
				int big = maxHeap.top(); maxHeap.pop();
				int small = minHeap.top(); minHeap.pop();
				maxHeap.push(small);
				minHeap.push(big);
			}

			if (i % 2 == 1) medians.push_back(maxHeap.top());
		}
		
		int size = (int)medians.size();
		cout << size << '\n';
		for (int i = 0; i < size; i++) {
			cout << medians[i] << ' ';
			if ((i + 1) % 10 == 0) cout << '\n';
		}
	}

	return 0;
}