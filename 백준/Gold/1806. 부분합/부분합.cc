#include <bits/stdc++.h>
using namespace std;

int arr[100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, s;
	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> arr[i];
	
	int ans = INT_MAX;
	int st = 0, en = 0;
	int sum = arr[0];
	while (st < n) {
		while (en < n && sum < s)
			sum += arr[++en];
		if (en == n) break;
		ans = min(ans, en - st + 1);
		sum -= arr[st++];
	}
	
	cout << (ans != INT_MAX ? ans : 0) << '\n';
	return 0;
}