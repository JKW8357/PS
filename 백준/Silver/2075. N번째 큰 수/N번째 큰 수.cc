#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<>> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int num;
			cin >> num;
			if (pq.size() < n) pq.push(num);
			else if (num > pq.top()) {
				pq.pop();
				pq.push(num);
			}
		}
	}

	cout << pq.top() << '\n';
	return 0;
}

// 메모리 제한을 고려해 최대 크기가 n인 priority_queue를 이용해야 한다.
