#include <bits/stdc++.h>
using namespace std;

int arr[250005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, x;
	cin >> n >> x;
	for (int i = 0; i < n; i++) cin >> arr[i];

	int sum = accumulate(arr, arr + x, 0);
	int mx = sum, cnt = 1;
	for (int i = x; i < n; i++) {
		sum += arr[i];
		sum -= arr[i - x];
		if (mx < sum) {
			mx = sum;
			cnt = 1;
		}
		else if (mx == sum) cnt++;
	}

	if (mx == 0) cout << "SAD\n";
	else cout << mx << '\n' << cnt << '\n';
	return 0;
}