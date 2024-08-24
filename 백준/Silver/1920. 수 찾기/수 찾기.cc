#include <bits/stdc++.h>
using namespace std;

int arr[100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);

	int m;
	cin >> m;
	while(m--) {
		int q;
		cin >> q;
		cout << (binary_search(arr, arr + n, q) ? 1 : 0) << '\n';
	}

	return 0;
}