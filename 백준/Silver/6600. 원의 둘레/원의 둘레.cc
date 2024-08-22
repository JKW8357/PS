#include <bits/stdc++.h>
using namespace std;
#define PI 3.141592653589793

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	double x1, y1, x2, y2, x3, y3;
	while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3) {
		double xa = x2 - x1, ya = y2 - y1, xb = x3 - x1, yb = y3 - y1;
		double angle = acos((xa * xb + ya * yb) / hypot(xa, ya) / hypot(xb, yb));
		double radius = hypot(x3 - x2, y3 - y2) / sin(angle) / 2;

		cout << fixed;
		cout.precision(2);
		cout << 2 * PI * radius << '\n';
	}

	return 0;
}