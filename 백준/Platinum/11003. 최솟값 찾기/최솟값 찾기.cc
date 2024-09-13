#include <bits/stdc++.h>
using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, l;
	cin >> n >> l;
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		pq.push({ num, i });
		while (pq.top().second < i - l + 1) pq.pop();
		cout << pq.top().first << ' ';
	}

	return 0;
}