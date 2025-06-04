#include <bits/stdc++.h>
using namespace std;

int n;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int board[505][505];
int dp[505][505];

int solve(int x, int y) {
    if (dp[x][y] != -1) return dp[x][y];
    dp[x][y] = 1;
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if (board[x][y] >= board[nx][ny]) continue;
        dp[x][y] = max(dp[x][y], solve(nx, ny) + 1);
    }
    return dp[x][y];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            dp[i][j] = -1;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ans = max(ans, solve(i, j));

    cout << ans << '\n';
    return 0;
}