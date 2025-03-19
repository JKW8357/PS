#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define F first
#define S second

vector<pii> squares;
pii dp[1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		squares.push_back({ a, b });
	}

	dp[0] = { squares[0].F, squares[0].S };
	for (int i = 1; i < n; i++) {
		auto [a, b] = squares[i];
		auto [prevA, prevB] = squares[i - 1];
		dp[i].F = max(dp[i - 1].F + abs(b - prevB), dp[i - 1].S + abs(b - prevA)) + a;
		dp[i].S = max(dp[i - 1].F + abs(a - prevB), dp[i - 1].S + abs(a - prevA)) + b;
	}

	cout << max(dp[n - 1].F, dp[n - 1].S) << '\n';
	return 0;
}