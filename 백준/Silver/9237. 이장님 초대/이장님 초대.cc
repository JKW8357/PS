#include <bits/stdc++.h>
using namespace std;

int arr[100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n, greater<int>());
	for (int i = 0; i < n; i++) arr[i] += i + 2;
	cout << *max_element(arr, arr + n) << '\n';

	return 0;
}