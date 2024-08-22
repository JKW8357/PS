#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	double xa, ya, xb, yb, xc, yc;
	cin >> xa >> ya >> xb >> yb >> xc >> yc;

	double len1 = hypot(xa - xb, ya - yb);
	double len2 = hypot(xb - xc, yb - yc);
	double len3 = hypot(xc - xa, yc - ya);

	double max_val = 2 * max({ fabs(len1 + len2), fabs(len1 + len3), fabs(len2 + len3) });
	double min_val = 2 * min({ fabs(len1 + len2), fabs(len1 + len3), fabs(len2 + len3) });

	cout << fixed;
	cout.precision(10);

	bool check = false;
	if (xb - xa == 0 && xc - xa == 0) check = true;
	else if ((xb - xa != 0 && xc - xa != 0) && (yb - ya) / (xb - xa) == (yc - ya) / (xc - xa)) check = true;
	cout << (check ? -1.0 : max_val - min_val) << '\n';
	return 0;
}