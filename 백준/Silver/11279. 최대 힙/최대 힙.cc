#include <bits/stdc++.h>
using namespace std;

priority_queue<int> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	while (n--) {
		int x; cin >> x;
		if (x > 0) pq.push(x);
		else {
			if (pq.empty()) cout << 0 << '\n';
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
	}
	
	return 0;
}