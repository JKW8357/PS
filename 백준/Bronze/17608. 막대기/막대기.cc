#include <bits/stdc++.h>
using namespace std;

int arr[100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	int cur = arr[n - 1];
	int cnt = 1;
	for (int i = n - 2; i >= 0; i--) {
		if (cur < arr[i]) {
			cur = arr[i];
			cnt++;
		}
	}

	cout << cnt << '\n';
	return 0;
}