#include <bits/stdc++.h>
using namespace std;

vector<int> p;

int find(int x) {
	if (p[x] == x) return x;
	return p[x] = find(p[x]);
}

void unionSets(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	else if (x > y) swap(x, y);
	p[y] = x;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int gate, plane;
	cin >> gate >> plane;
	for (int i = 0; i <= gate; i++) p.push_back(i);

	int cnt = 0;
	while (plane--) {
		int i; cin >> i;
		i = find(i);
		if (i == 0) break;
		unionSets(i, i - 1);
		cnt++;
	}
	
	cout << cnt << '\n';
	return 0;
}