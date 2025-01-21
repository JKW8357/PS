#include <bits/stdc++.h>
using namespace std;
typedef pair<double, double> p;
#define x first
#define y second

int stats[8];

double ccw(const p& a, const p& b, const p& c) {
	return (a.x * b.y + b.x * c.y + c.x * a.y) - (b.x * a.y + c.x * b.y + a.x * c.y);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 8; i++) cin >> stats[i];
	vector<int> perm = { 0,1,2,3,4,5,6,7 };
	
	int ans = 0;
	do {
		bool check = true;
		for (int i = 0; i < 8; i++) {
			p a = { stats[perm[i]], 0 };
			p b = { stats[perm[(i + 1) % 8]] * sqrt(2) / 2, stats[perm[(i + 1) % 8]] * sqrt(2) / 2 };
			p c = { 0, stats[perm[(i + 2) % 8]] };
			double d = ccw(a, b, c);
			if (d <= 0) {
				check = false;
				break;
			}
		}
		if (check) ans++;
	} while (next_permutation(perm.begin(), perm.end()));

	cout << ans << '\n';
	return 0;
}