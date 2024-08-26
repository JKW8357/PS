#include <bits/stdc++.h>
using namespace std;

int m[35];
int n[35];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int d, k;
	cin >> d >> k;

	m[1] = 1, n[1] = 0;
	m[2] = 0, n[2] = 1;

	for (int i = 3; i <= d; i++) {
		m[i] = m[i - 1] + m[i - 2];
		n[i] = n[i - 1] + n[i - 2];
	}

	for (int a = 1; a <= k; a++) {
		if ((k - m[d] * a) % n[d] == 0) {
			cout << a << '\n' << (k - m[d] * a) / n[d];
			break;
		}
	}

	return 0;
}