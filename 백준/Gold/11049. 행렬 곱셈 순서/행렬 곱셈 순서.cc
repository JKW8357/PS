#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
const int INF = (int)1e9;

pair<int, int> matrix[505];
int sum[505][505];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> matrix[i].X >> matrix[i].Y;

	for (int term = 1; term <= n - 1; term++) {
		for (int st = 1; st + term <= n; st++) {
			int en = st + term;
			sum[st][en] = INF;
			for (int k = st; k < en; k++) {
				int cost = sum[st][k] + sum[k + 1][en] + matrix[st].X * matrix[k].Y * matrix[en].Y;
				sum[st][en] = min(sum[st][en], cost);
			}
		}
	}

	cout << sum[1][n] << '\n';
	return 0;
}