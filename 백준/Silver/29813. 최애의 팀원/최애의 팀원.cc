#include <bits/stdc++.h>
using namespace std;

string name;
int num;
queue<pair<string, int>> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	while (n--) {
		cin >> name >> num;
		q.push({ name, num });
	}

	while (q.size() != 1) {
		auto cur = q.front(); q.pop();
		while (--cur.second) { q.push(q.front()); q.pop(); }
		q.pop();
	}

	cout << q.front().first << '\n';
	return 0;
}