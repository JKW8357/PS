#include <bits/stdc++.h>
using namespace std;

int arr[105][105];
bool check[10005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check[arr[i][j]]) {
				cout << "FALSE\n";
				return 0;
			}
			check[arr[i][j]] = true;
		}
	}

	int sum = accumulate(arr[0], arr[0] + n, 0);
	
	for (int i = 0; i < n; i++) {
		int row = 0;
		for (int j = 0; j < n; j++) row += arr[i][j];
		if (row != sum) {
			cout << "FALSE\n";
			return 0;
		}
	}

	for (int j = 0; j < n; j++) {
		int col = 0;
		for (int i = 0; i < n; i++) col += arr[i][j];
		if (col != sum) {
			cout << "FALSE\n";
			return 0;
		}
	}

	int diag1 = 0, diag2 = 0;
	for (int i = 0; i < n; i++) {
		diag1 += arr[i][i];
		diag2 += arr[n - 1 - i][i];
	}
	if (diag1 != sum || diag2 != sum) {
		cout << "FALSE\n";
		return 0;
	}

	cout << "TRUE\n";
	return 0;
}