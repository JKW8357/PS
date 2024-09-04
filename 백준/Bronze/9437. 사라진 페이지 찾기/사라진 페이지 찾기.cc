#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;

		int p;
		cin >> p;

		int num1, num2, num3;
		num1 = n + 1 - p;
		num2 = max(p, num1) + (min(p, num1) % 2 == 0 ? 1 : -1);
		num3 = min(p, num1) + (min(p, num1) % 2 == 0 ? -1 : 1);

		int min_val = min({ num1, num2, num3 });
		int max_val = max({ num1, num2, num3 });
		cout << min_val << ' ' << 2 * (n + 1) - min_val - max_val - p << ' ' << max_val << '\n';
	}

	return 0;
}