#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int xa1, ya1, xa2, ya2, xb1, yb1, xb2, yb2;
	for (int i = 0; i < 4; i++) {
		cin >> xa1 >> ya1 >> xa2 >> ya2 >> xb1 >> yb1 >> xb2 >> yb2;
		if (xa2 < xb1 || xb2 < xa1 || ya2 < yb1 || yb2 < ya1) cout << 'd' << '\n';
		else if ((xa1 == xb2 || xa2 == xb1) && (ya1 == yb2 || ya2 == yb1)) cout << 'c' << '\n';
		else if (xa1 == xb2 || xa2 == xb1 || ya1 == yb2 || ya2 == yb1) cout << 'b' << '\n';
		else cout << 'a' << '\n';
	}
	
	return 0;
}