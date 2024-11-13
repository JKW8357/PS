#include <bits/stdc++.h>
using namespace std;

int digitCnt[10];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	while (cin >> n >> m) {
		int cnt = m - n + 1;
		for (int i = n; i <= m; i++) {
			fill(digitCnt, digitCnt + 10, 0);
			int num = i;
			while (num != 0) {
				digitCnt[num % 10]++;
				num /= 10;
			}
			for (int j = 0; j < 10; j++) {
				if (digitCnt[j] > 1) {
					cnt--;
					break;
				}
			}
		}
		cout << cnt << '\n';
	}

	return 0;
}