#include <bits/stdc++.h>
using namespace std;

int board[505][505];
int sum[505][505];
int zeros[505][505];
int d[100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
            sum[i][j] = board[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
            zeros[i][j] = (int)(board[i][j] == 0) + zeros[i - 1][j] + zeros[i][j - 1] - zeros[i - 1][j - 1];
        }
    }

    int k; cin >> k;
    for (int i = 1; i <= k; i++) cin >> d[i];
    sort(d + 1, d + k + 1, greater<int>());
    for (int i = 2; i <= k; i++) d[i] += d[i - 1];

    int maxVal = 0;
    for (int s = 1; s <= n; s++) {
        for (int i = s; i <= n; i++) {
            for (int j = s; j <= n; j++) {
                int curVal = sum[i][j] - sum[i - s][j] - sum[i][j - s] + sum[i - s][j - s];
                int curZeros = zeros[i][j] - zeros[i - s][j] - zeros[i][j - s] + zeros[i - s][j - s];
                if (curZeros <= k) maxVal = max(maxVal, curVal + d[curZeros]);
            }
        }
    }

    cout << maxVal << '\n';
    return 0;
}