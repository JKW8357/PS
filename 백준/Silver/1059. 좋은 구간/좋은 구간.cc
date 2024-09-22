#include <bits/stdc++.h>
using namespace std;

int arr[55];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int l;
	cin >> l;
	
	arr[0] = 0;
	for (int i = 1; i <= l; i++) cin >> arr[i];
	sort(arr, arr + l + 1);

	int n;
	cin >> n;

	for (int i = 1; i <= l; i++) {
		if (arr[i] > n) {
			int st = arr[i - 1] + 1;
			int en = arr[i] - 1;
			cout << (n - st) * (en - n + 1) + (en - n) << '\n';
			break;
		}

		else if (arr[i] == n) {
			cout << 0 << '\n';
			break;
		}
	}

	return 0;
}