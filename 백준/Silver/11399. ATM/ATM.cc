#include <bits/stdc++.h>
using namespace std;

int arr[1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);

	int sum = 0;
	for (int i = 0; i < n; i++) sum += arr[i] * (n - i);
	cout << sum;

	return 0;
}