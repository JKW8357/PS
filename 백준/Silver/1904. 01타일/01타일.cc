#include <iostream>

using namespace std;

int dp[1000001];

int main()
{
	/* 뒤에 00 또는 1이 오는 경우로 이분법적으로 나누자
	1
	00 11
	100 // 001 111
	0000 1100 // 1001 0011 1111
	*/

	int n;
	cin >> n;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; ++i) {
		dp[i] = (dp[i - 2] + dp[i - 1]) % 15746;
	}
	cout << dp[n];
}