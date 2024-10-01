#include <bits/stdc++.h>
using namespace std;

queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) q.push(i);

	while(true) {
		cout << q.front() << ' '; q.pop();
		if (q.empty()) break;
		int tmp = q.front();
		q.push(tmp); q.pop();
	}

	return 0;
}