#include <bits/stdc++.h>
using namespace std;

int arr[200005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);

	cout << arr[(n - 1) / 2] << '\n';
	return 0;
}