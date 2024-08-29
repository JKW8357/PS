#include <bits/stdc++.h>
using namespace std;

int plum[1005];
int dp[1005][35];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t, w;
	cin >> t >> w;
	for (int i = 1; i <= t; i++) cin >> plum[i];

	for (int i = 1; i <= t; i++) {
		if (plum[i] == 1) dp[i][0] = dp[i - 1][0] + 1;
		for (int j = 1; j <= w; j++) {
			if (i < j) break;
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + ((j + plum[i]) % 2 != 0 ? 1 : 0);
		}
	}

	cout << *max_element(dp[t], dp[t] + w + 1) << '\n';
	return 0;
}

/*
자두가 움직인 횟수가 홀수일 경우 2번 나무, 짝수일 경우 1번 나무에 가게 된다.
dp[i][j]일 때 자두가 1번 나무에 있을 때와 2번 나무에 있을 때 각각의 자두 개수의 최댓깂을 구한다.
그리고 '모든 j(이동 횟수)'에 대해 자두 개수의 최댓값을 구한다.
(dp[t][w]가 자두 개수의 최댓값이라는 보장은 없다.)
*/