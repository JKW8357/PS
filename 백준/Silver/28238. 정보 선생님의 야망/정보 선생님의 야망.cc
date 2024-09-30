#include <bits/stdc++.h>
using namespace std;

int arr[1000005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int student = 0;
		for (int j = 0; j < 5; j++) {
			int day;
			cin >> day;
			student |= (day << j);
		}
		arr[i] = student;
	}

	int max_stud = 0;
	int day1 = 0, day2 = 1;

	for (int j = 0; j < 4; j++) {
		for (int k = j + 1; k < 5; k++) {
			int cnt = 0;
			int days = (1 << j | 1 << k);
			for (int i = 0; i < n; i++)
				if ((arr[i] & days) == days) cnt++;
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