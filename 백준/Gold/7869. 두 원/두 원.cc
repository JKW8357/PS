#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	double x1, y1, r1, x2, y2, r2;
	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
	double dist = hypot(x2 - x1, y2 - y1);
	double ans = 0;

	if (dist >= r1 + r2) ans = 0;
	else if (dist <= abs(r1 - r2)) ans = PI * min(r1 * r1, r2 * r2);
	else {
		double a1 = 2 * acos((dist * dist + r1 * r1 - r2 * r2) / (2 * dist * r1));
		double a2 = 2 * acos((dist * dist + r2 * r2 - r1 * r1) / (2 * dist * r2));
		ans = 0.5 * r1 * r1 * (a1 - sin(a1)) + 0.5 * r2 * r2 * (a2 - sin(a2));
	}

	cout << fixed << setprecision(3) << ans << '\n';
	return 0;
}