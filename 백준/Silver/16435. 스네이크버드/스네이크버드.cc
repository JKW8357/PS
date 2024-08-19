#include <bits/stdc++.h>
using namespace std;

int arr[1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, l;
	cin >> n >> l;

	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);

	for (int i = 0; i < n; i++) {
		if (l >= arr[i]) l++;
		else break;
	}

	cout << l << '\n';
	return 0;
}