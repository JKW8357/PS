#include <bits/stdc++.h>
using namespace std;

int board1[1005][1005];
int board2[1005][1005];

void solve(int n, int k) {
	if (n * n / 2 > k || (n % 2 == 0 && k % 2 == 1)) {
		cout << -1 << '\n';
		return;
	}

	int coin1 = k; int coin2 = k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((i + j) % 2 == 0) {
				board1[i][j]++;
				coin1--;
			}
			else {
				board2[i][j]++;
				coin2--;
			}
		}
	}

	int q1 = coin1 / (n * n); coin1 -= q1 * (n * n);
	int q2 = coin2 / (n * n); coin2 -= q2 * (n * n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			board1[i][j] += q1;
			board2[i][j] += q2;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((i + j) % 2 == 1) {
				if (!coin1) {
					for (int i = 0; i < n; i++) {
						for (int j = 0; j < n; j++)
							cout << board1[i][j] << ' ';
						cout << '\n';
					}
					return;
				}
				board1[i][j] += 2;
				coin1 -= 2;
			}
			else {
				if (!coin2) {
					for (int i = 0; i < n; i++) {
						for (int j = 0; j < n; j++)
							cout << board2[i][j] << ' ';
						cout << '\n';
					}
					return;
				}
				board2[i][j] += 2;
				coin2 -= 2;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;
	solve(n, k);

	return 0;
}