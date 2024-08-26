#include <bits/stdc++.h>
using namespace std;

string arr[55];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = i + 1; j < n; j++)
			if (arr[i] == arr[j].substr(0, arr[i].size())) cnt++;
		if (cnt == 0) ans++;
	}
	
	cout << ans << '\n';
	return 0;
}