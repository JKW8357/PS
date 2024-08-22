#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	double x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	bool check = true;

	if (x1 == x2 && x1 == x3) check = false;
	else if (x1 == x2 || x1 == x3) check = true;
	else if ((y1 - y2) / (x1 - x2) == (y1 - y3) / (x1 - x3)) check = false;
	cout << (check ? "WINNER WINNER CHICKEN DINNER!" : "WHERE IS MY CHICKEN?") << '\n';

	return 0;
}