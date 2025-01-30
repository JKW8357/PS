#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> matrix;
const int mod = (int)(1e9 + 7);

matrix operator * (matrix& m1, matrix& m2) {
	matrix result = { {0, 0}, {0, 0} };
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				result[i][j] += m1[i][k] * m2[k][j];
				result[i][j] %= mod;
			}
		}
	}
	return result;
}

matrix power(matrix m, ll n) {
	matrix result = { {1, 0}, {0, 1} };
	while (n > 0) {
		if (n % 2 == 1) {
			result = result * m;
			n -= 1;
		}
		m = m * m;
		n /= 2;
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll n; cin >> n;
	matrix f = { {1, 1}, {1, 0} };
	matrix ans = power(f, n);
	cout << ans[0][1] << '\n';

	return 0;
}