#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> matrix;

ll n, b;

matrix matrixMultiply(const matrix& m1, const matrix& m2) {
	matrix result(n, vector<ll>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				result[i][j] += m1[i][k] * m2[k][j];
				result[i][j] %= 1000;
			}
		}
	}
	return result;
}

matrix solve(matrix arr, ll pow) {
	if (pow == 1) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				arr[i][j] %= 1000;
		return arr;
	}

	matrix tmp = solve(arr, pow / 2);
	if (pow % 2 == 0) return matrixMultiply(tmp, tmp);
	else return matrixMultiply(matrixMultiply(tmp, tmp), arr);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> b;
	matrix arr(n, vector<ll>(n, 0));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	matrix ans = solve(arr, b);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cout << ans[i][j] << ' ';
		cout << '\n';
	}

	return 0;
}