#include <bits/stdc++.h>
using namespace std;

int arr[1000005][5];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < 5; j++) cin >> arr[i][j];

	int max_stud = 0;
	int day1 = 1;
	int day2 = 2;

	for (int j = 0; j < 4; j++) {
		for (int k = j + 1; k < 5; k++) {
			int cnt = 0;
			for (int i = 0; i < n; i++)
				if (arr[i][j] == 1 && arr[i][k] == 1) cnt++;

			if (max_stud < cnt) {
				max_stud = cnt;
				day1 = j;
				day2 = k;
			}
		}
	}

	cout << max_stud << '\n';
	for (int i = 0; i < 5; i++) cout << (i == day1 || i == day2 ? "1 " : "0 ");
	cout << '\n';
	return 0;
}