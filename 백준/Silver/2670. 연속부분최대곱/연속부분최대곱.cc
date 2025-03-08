#include <bits/stdc++.h>
using namespace std;

double arr[10005];
double dp[10005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	
	double ans = 0;
	dp[1] = arr[1];
	for (int i = 2; i <= n; i++) {
		dp[i] = max(arr[i] * dp[i - 1], arr[i]);
		ans = max(ans, dp[i]);
	}
	
	cout << fixed << setprecision(3) << ans << '\n';
	return 0;
}