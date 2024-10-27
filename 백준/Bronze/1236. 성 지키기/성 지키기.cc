#include <bits/stdc++.h>
using namespace std;

char arr[55][55];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	int cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < n; i++) {
		bool flag = true;
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 'X') {
				flag = false;
				break;
			}
		}
		if (flag) cnt1++;
	}

	for (int j = 0; j < m; j++) {
		bool flag = true;
		for (int i = 0; i < n; i++) {
			if (arr[i][j] == 'X') {
				flag = false;
				break;
			}
		}
		if (flag) cnt2++;
	}

	cout << max(cnt1, cnt2) << '\n';
	return 0;
}