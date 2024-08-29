#include <bits/stdc++.h>
using namespace std;

priority_queue<double, vector<double>, greater<>> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		double num;
		cin >> num;
		pq.push(num);
	}

	cout << fixed;
	cout.precision(3);
	for (int i = 0; i < 7; i++) {
		cout << pq.top() << '\n';
		pq.pop();
	}

	return 0;
}