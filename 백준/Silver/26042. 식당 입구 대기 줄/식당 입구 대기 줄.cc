#include <bits/stdc++.h>
using namespace std;

queue<int> q;
int maxCount = 0;
int lastNum = INT_MAX;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	while (n--) {
		int cmd;
		cin >> cmd;

		if (cmd == 1) {
			int a;
			cin >> a;
			q.push(a);
		}

		else q.pop();

		if (maxCount <= q.size()) {
			lastNum = (maxCount == q.size() ? min(lastNum, q.back()) : q.back());
			maxCount = q.size();
		}
	}

	cout << maxCount << ' ' << lastNum << '\n';
	return 0;
}