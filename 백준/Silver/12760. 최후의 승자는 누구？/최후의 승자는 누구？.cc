#include <bits/stdc++.h>
using namespace std;

priority_queue<int> arr[105];
int points[105];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			int num;
			cin >> num;
			arr[i].push(num);
		}
	}
	
	while (m--) {
		int maxVal = 0;
		for (int i = 1; i <= n; i++) maxVal = max(maxVal, arr[i].top());
		for (int i = 1; i <= n; i++) {
			if (arr[i].top() == maxVal) points[i]++;
			arr[i].pop();
		}
	}

	int maxPoints = 0;
	for (int i = 1; i <= n; i++) maxPoints = max(maxPoints, points[i]);
	for (int i = 1; i <= n; i++)
		if (points[i] == maxPoints) cout << i << ' ';

	return 0;
}