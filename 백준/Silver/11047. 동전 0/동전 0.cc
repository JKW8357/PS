#include <bits/stdc++.h>
using namespace std;

int arr[10];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> arr[i];

	int cnt = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (k == 0) break;
		cnt += k / arr[i];
		k %= arr[i];
	}
	
	cout << cnt << '\n';
	return 0;
}