#include <bits/stdc++.h>
using namespace std;

int dp[45];
vector<int> vips = { 0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	while(m--) {
		int vip;
		cin >> vip;
		vips.push_back(vip);
	}
	vips.push_back(n + 1);

	dp[0] = 1; // VIP석끼리 맞붙은 경우도 고려
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++)
		dp[i] = dp[i - 1] + dp[i - 2];

	int ans = 1;
	for (int i = 1; i < vips.size(); i++)
		ans *= dp[vips[i] - vips[i - 1] - 1];

	cout << ans << '\n';
	return 0;
}

/*
dp[i] = dp[i - 1] + dp[i - 2]
: i번째 자리에 앉는 경우의 수는
  - (i-1)번째 자리까지 고정하고 i번째 사람이 i번째 자리에 앉는 경우
  - (i-2)번째 자리까지 고정하고 (i-1)번째, i번째 사람이 각각 i번째 자리, (i-1)번째 자리에 앉는 경우
  이 두 가지 경우의 합
*/