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

bool isIntersect(p& p1, p& p2, p& p3, p& p4) {
	int p1p2 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
	int p3p4 = ccw(p3, p4, p1) * ccw(p3, p4, p2);

	if (p1p2 == 0 && p3p4 == 0)
		return max(p1, p2) >= min(p3, p4) && max(p3, p4) >= min(p1, p2);

	return p1p2 <= 0 && p3p4 <= 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	p p1, p2, p3, p4;
	cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;
	cout << (isIntersect(p1, p2, p3, p4) ? 1 : 0) << '\n';

	return 0;
}