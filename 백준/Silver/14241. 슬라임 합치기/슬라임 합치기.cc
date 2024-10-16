#include <bits/stdc++.h>
using namespace std;

queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	while (n--) {
		int num;
		cin >> num;
		q.push(num);
	}

	int score = 0;
	while (q.size() > 1) {
		int num1 = q.front(); q.pop();
		int num2 = q.front(); q.pop();
		score += num1 * num2;
		q.push(num1 + num2);
	}
	
	cout << score << '\n';
	return 0;
}