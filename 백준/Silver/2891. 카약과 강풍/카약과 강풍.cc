#include <bits/stdc++.h>
using namespace std;

int arr[12];
bool borrowed[12];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, s, r;
	cin >> n >> s >> r;

	fill(arr + 1, arr + n + 1, 1);

	for (int i = 0; i < s; i++) {
		int num;
		cin >> num;
		arr[num]--;
	}

	for (int i = 0; i < r; i++) {
		int num;
		cin >> num;
		arr[num]++;
	}

	for (int i = 1; i <= n; i++) {
		if (arr[i] == 1) continue;
		if (i > 1 && !borrowed[i - 1] && arr[i - 1] == 0 && arr[i] == 2) {
			arr[i - 1]++;
			arr[i]--;
			borrowed[i - 1] = true;
			continue;
		}
		if (i < n && !borrowed[i + 1] && arr[i + 1] == 0 && arr[i] == 2) {
			arr[i + 1]++;
			arr[i]--;
			borrowed[i + 1] = true;
		}
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (arr[i] == 0) cnt++;
	cout << cnt;

	return 0;
}