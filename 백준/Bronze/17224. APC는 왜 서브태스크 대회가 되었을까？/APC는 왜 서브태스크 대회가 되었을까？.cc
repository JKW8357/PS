#include <bits/stdc++.h>
using namespace std;

int arr[105];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, l, k;
	cin >> n >> l >> k;

	for (int i = 0; i < n; i++) {
		int easy, hard;
		cin >> easy >> hard;
		if (easy <= l) arr[i] = 100;
		if (hard <= l) arr[i] = 140;
	}

	sort(arr, arr + n, greater<int>());
	int ans = accumulate(arr, arr + k, 0);
	cout << ans;

	return 0;
}