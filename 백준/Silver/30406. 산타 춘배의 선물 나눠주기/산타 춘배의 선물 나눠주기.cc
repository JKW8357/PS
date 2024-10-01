#include <bits/stdc++.h>
using namespace std;

int ans = 0;
int arr[4];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	
	while (n--) {
		int price;
		cin >> price;
		arr[price]++;
	}

	int cnt1 = min(arr[0], arr[3]);
	arr[0] -= cnt1;
	arr[3] -= cnt1;
	ans += cnt1 * 3;

	int cnt2 = min(arr[1], arr[2]);
	arr[1] -= cnt2;
	arr[2] -= cnt2;
	ans += cnt2 * 3;

	for (int i = 0; i < 3; i++)
		for (int j = i + 1; j < 4; j++)
			ans += abs(i - j) * min(arr[i], arr[j]);

	cout << ans << '\n';
	return 0;
}