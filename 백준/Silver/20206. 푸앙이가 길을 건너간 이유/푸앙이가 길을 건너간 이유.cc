#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, c;
	cin >> a >> b >> c;

	int x1, x2, y1, y2;
	cin >> x1 >> x2 >> y1 >> y2;

	int above = 0, below = 0;
	vector<pair<int, int>> points = {{x1, y1}, {x1, y2}, {x2, y1}, {x2, y2}};
	for (auto p : points) {
		if (a * p.first + b * p.second + c >= 0) above++;
		if (a * p.first + b * p.second + c <= 0) below++;
	}

	cout << (above == 0 || above == 4 || below == 0 || below == 4 ? "Lucky\n" : "Poor\n");

	return 0;
}