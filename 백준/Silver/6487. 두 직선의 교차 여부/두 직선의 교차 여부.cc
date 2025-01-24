#include <bits/stdc++.h>
using namespace std;

struct point {
	double x, y;
};

void getIntersection(const point& p1, const point& p2, const point& p3, const point& p4) {
	double a1 = p1.x - p2.x;
	double b1 = p1.y - p2.y;
	double c1 = p1.x * p2.y - p2.x * p1.y;

	double a2 = p3.x - p4.x;
	double b2 = p3.y - p4.y;
	double c2 = p3.x * p4.y - p4.x * p3.y;

	double d = a1 * b2 - a2 * b1;
	double px = (c1 * a2 - c2 * a1) / d;
	double py = (c1 * b2 - c2 * b1) / d;

	cout << px << ' ' << py << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cout << fixed << setprecision(2);
	int tc; cin >> tc;
	while (tc--) {
		point p1, p2, p3, p4;
		cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;

		if (p1.x == p2.x && p3.x == p4.x) {
			if (p1.x == p3.x) cout << "LINE\n";
			else cout << "NONE\n";
			continue;
		}

		if (p1.x == p2.x) {
			double slope2 = (p4.y - p3.y) / (p4.x - p3.x);
			double section2 = p3.y - slope2 * p3.x;
			double py = slope2 * p1.x + section2;
			cout << "POINT " << p1.x << ' ' << py << '\n';
			continue;
		}

		if (p3.x == p4.x) {
			double slope1 = (p2.y - p1.y) / (p2.x - p1.x);
			double section1 = p1.y - slope1 * p1.x;
			double py = slope1 * p3.x + section1;
			cout << "POINT " << p3.x << ' ' << py << '\n';
			continue;
		}

		double slope1 = (p2.y - p1.y) / (p2.x - p1.x);
		double slope2 = (p4.y - p3.y) / (p4.x - p3.x);

		double section1 = p1.y - slope1 * p1.x;
		double section2 = p3.y - slope2 * p3.x;

		if (slope1 == slope2 && section1 == section2) cout << "LINE\n";
		else if (slope1 == slope2) cout << "NONE\n";
		else {
			cout << "POINT ";
			getIntersection(p1, p2, p3, p4);
		}
	}

	return 0;
}