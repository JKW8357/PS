#include <bits/stdc++.h>
using namespace std;

priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (i % 2 == 0) maxHeap.push(num);
		else minHeap.push(num);
		
		if (!maxHeap.empty() && !minHeap.empty() && maxHeap.top() > minHeap.top()) {
			int big = maxHeap.top(); maxHeap.pop();
			int small = minHeap.top(); minHeap.pop();
			maxHeap.push(small);
			minHeap.push(big);
		}

		cout << maxHeap.top() << '\n';
	}

	return 0;
}