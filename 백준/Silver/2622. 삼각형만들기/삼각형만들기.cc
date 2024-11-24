#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	int cnt = 0;
	
	for (int a = 1; a <= n / 3; a++) {
		for (int b = a; b <= (n - a) / 2; b++) {
			int c = n - a - b;
			if (a + b > c) cnt++;
		}
	}

	cout << cnt << '\n';
	return 0;
}