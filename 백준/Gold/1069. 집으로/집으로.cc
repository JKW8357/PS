#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	double x, y, d, t;
	cin >> x >> y >> d >> t;

	double dist = hypot(x, y);
	int jump = dist / d;

	double time = 0;
	if (dist >= d) time = min({ dist, t * jump + (dist - jump * d), t * (jump + 1)});
	else time = min({ dist, t + d - dist, t * 2 });
	cout << fixed << setprecision(9) << time << '\n';

	return 0;
}