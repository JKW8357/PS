#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int maxx = -11, minx = 11, maxy = -11, miny = 11;

	int n;
	cin >> n;

	while (n--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		maxx = max(maxx, x2);
		maxy = max(maxy, y2);
		minx = min(minx, x1);
		miny = min(miny, y1);
	
		cout << 2 * ((maxx - minx) + (maxy - miny)) << '\n';
	}

	return 0;
}