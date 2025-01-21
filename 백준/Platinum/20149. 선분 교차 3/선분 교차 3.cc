#include <bits/stdc++.h>
using namespace std;
typedef pair<double, double> p;
#define x first
#define y second

int ccw(const p& a, const p& b, const p& c) {
	double d = (a.x * b.y + b.x * c.y + c.x * a.y) - (b.x * a.y + c.x * b.y + a.x * c.y);
	if (d > 0) return 1;
	else if (d < 0) return -1;
	else return 0;
}

void getIntersection(const p& p1, const p& p2, const p& p3, const p& p4) {
	double a1 = p1.x - p2.x;
	double b1 = p1.y - p2.y;
	double c1 = p1.x * p2.y - p2.x * p1.y;

	double a2 = p3.x - p4.x;
	double b2 = p3.y - p4.y;
	double c2 = p3.x * p4.y - p4.x * p3.y;

	double d = a1 * b2 - a2 * b1;

	if (d == 0) {
		if (max(p1, p2) == min(p3, p4)) cout << max(p1, p2).x << ' ' << max(p1, p2).y << '\n';
		if (max(p3, p4) == min(p1, p2)) cout << max(p3, p4).x << ' ' << max(p3, p4).y << '\n';
		return;
	}

	double px = (c1 * a2 - c2 * a1) / d;
	double py = (c1 * b2 - c2 * b1) / d;

	cout << px << ' ' << py << '\n';
}

void solve(p& p1, p& p2, p& p3, p& p4) {
	int p1p2 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
	int p3p4 = ccw(p3, p4, p1) * ccw(p3, p4, p2);

	if (p1p2 == 0 && p3p4 == 0) {
		if (max(p1, p2) >= min(p3, p4) && max(p3, p4) >= min(p1, p2)) {
			cout << 1 << '\n';
			getIntersection(p1, p2, p3, p4);
		}
		else cout << 0 << '\n';
	}

	else {
		if (p1p2 <= 0 && p3p4 <= 0) {
			cout << 1 << '\n';
			getIntersection(p1, p2, p3, p4);
		}
		else cout << 0 << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	p p1, p2, p3, p4;
	cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;
	cout << fixed << setprecision(9);
	solve(p1, p2, p3, p4);

	return 0;
}