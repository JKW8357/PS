#include <bits/stdc++.h>
using namespace std;
typedef pair<double, double> p;
#define x first
#define y second

double ccw(const p& a, const p& b, const p& c) {
	return (a.x * b.y + b.x * c.y + c.x * a.y) - (b.x * a.y + c.x * b.y + a.x * c.y);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	p a, b, c;
	cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
	double d = ccw(a, b, c);
	if (d > 0) cout << 1 << '\n';
	else if (d < 0) cout << -1 << '\n';
	else cout << 0 << '\n';

	return 0;
}