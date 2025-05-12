#include <bits/stdc++.h>
using namespace std;

int arr[1005];
int dp[1005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	
	fill(dp, dp + n, 1);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++)
			if (arr[i] > arr[j]) dp[i] = max(dp[i], dp[j] + 1);

	cout << *max_element(dp, dp + n) << '\n';
    return 0;
}