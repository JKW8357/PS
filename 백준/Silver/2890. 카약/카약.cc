#include <bits/stdc++.h>
using namespace std;

string m[55];
int res[10];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int r, c;
	cin >> r >> c;

	for (int i = 0; i < r; i++) cin >> m[i];

	int rank = 1;
	for (int j = c - 2; j >= 1; j--) {
		bool flag = false;
		for (int i = 0; i < r; i++) {
			if (res[m[i][j] - '0'] == 0 && m[i][j] != '.') {
				res[m[i][j] - '0'] = rank;
				flag = true;
			}
		}
		if (flag) rank++;
	}

	for (int i = 1; i <= 9; i++) cout << res[i] << '\n';
	return 0;
}