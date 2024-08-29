#include <bits/stdc++.h>
using namespace std;
#define MAX 1e9

int jump[22][2];
int dp[22][2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n;
	for (int i = 1; i <= n - 1; i++) cin >> jump[i][0] >> jump[i][1];
	cin >> k;

	for (int i = 0; i <= n; i++) dp[i][0] = dp[i][1] = MAX;
	dp[1][0] = 0;
	dp[2][0] = jump[1][0];

	for (int i = 3; i <= n; i++) {
		dp[i][0] = min(dp[i - 1][0] + jump[i - 1][0], dp[i - 2][0] + jump[i - 2][1]);
		dp[i][1] = min({ dp[i - 1][1] + jump[i - 1][0], dp[i - 2][1] + jump[i - 2][1], dp[i - 3][0] + k });
	}

	cout << min(dp[n][0], dp[n][1]) << '\n';
	return 0;
}

/*
dp 배열을 INT_MAX로 채워넣으면 오버플로가 발생하니 주의, MAX = 10^9 정도로 적당한 값 넣기
dp[0][0], dp[0][1], dp[1][1], dp[2][1], dp[3][1]은 존재하지 않지만, 점화식을 깔끔하게 작성하기 위해
MAX 값으로 모두 할당해주고 나면 min 함수 내에서 자연스레 최솟값이 처리될 것
괜히 스스로 점화식을 불필요한 조건 등으로 복잡하게 만들면 반례가 생기거나 점화식이 꼬이는 경우가 매우 많으니 주의
*/
