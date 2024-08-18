#include <bits/stdc++.h>
using namespace std;

long long dp[65][10];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int tc;
	cin >> tc;

	while (tc--) {
		int n;
		cin >> n;

		for (int i = 1; i <= n; i++) {
			dp[i][0] = 1;
			for (int j = 1; j <= 9; j++)
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}

		long long ans = accumulate(dp[n], dp[n] + 10, 0LL);
		cout << ans << '\n';
	}

	return 0;
}

/*
<accumulate() 사용 시 주의사항>

accumulate 함수는 초기값의 타입을 기준으로 연산하므로,
자료형에 따라 정확히 초기값의 타입을 명시해
암묵적 형변환으로 인한 오버플로 또는 데이터 손실을 방지해야 한다.

int: 0
long long: 0LL
unsigned long long
float: 0.0f
double: 0.0
char: '\0'
bool: false;
pointer: nullptr
*/
