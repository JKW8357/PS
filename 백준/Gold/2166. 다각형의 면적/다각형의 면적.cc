#include <bits/stdc++.h>
using namespace std;
typedef pair<double, double> p;
#define x first
#define y second

vector<p> points;

double ccw(const p& a, const p& b, const p& c) {
	return (a.x * b.y + b.x * c.y + c.x * a.y) - (b.x * a.y + c.x * b.y + a.x * c.y);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		double x, y;
		cin >> x >> y;
		points.push_back({ x, y });
	}

	double ans = 0;
	for (int i = 1; i < (int)points.size(); i++)
		ans += ccw(points[0], points[i - 1], points[i]) / 2;
	cout << fixed << setprecision(1) << abs(ans) << '\n';

	return 0;
}