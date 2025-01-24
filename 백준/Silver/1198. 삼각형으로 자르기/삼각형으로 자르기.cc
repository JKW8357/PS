#include <bits/stdc++.h>
using namespace std;

struct point {
	double x, y;
};

vector<point> points;

double ccw(const point& a, const point& b, const point& c) {
	return (a.x * b.y + b.x * c.y + c.x * a.y) - (b.x * a.y + c.x * b.y + a.x * c.y);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n; cin >> n;
	points.resize(n);
	for (int i = 0; i < n; i++) cin >> points[i].x >> points[i].y;

	double ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			for (int k = j + 1; k < n; k++)
				ans = max(ans, abs(ccw(points[i], points[j], points[k]) / 2));

	cout << fixed << setprecision(9) << ans << '\n';
	return 0;
}