#include <bits/stdc++.h>
using namespace std;

int arr[1000005];
int board[1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int r, c, n;
	cin >> r >> c >> n;
	
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);

	int idx = 0, ans = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			while (idx < n && board[j] == arr[idx]) idx++;
			if (idx == n) break;
			board[j] = arr[idx++];
			ans++;
		}
	}
	cout << ans;
	return 0;
}