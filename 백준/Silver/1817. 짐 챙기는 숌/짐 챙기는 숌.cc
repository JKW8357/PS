#include <bits/stdc++.h>
using namespace std;

int arr[1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	cin >> n >> m;

	if (n == 0) {
		cout << 0 << '\n';
		return 0;
	}

	for (int i = 0; i < n; i++) cin >> arr[i];

	int cnt = 1, weight = m;
	for (int i = 0; i < n; i++) {
		if (weight - arr[i] < 0) {
			weight = m;
			cnt++;
		}
		weight -= arr[i];
	}

	cout << cnt << '\n';
	return 0;
}