#include <bits/stdc++.h>
using namespace std;

int n;
int dx[8] = { -2,-2,-1,-1,1,1,2,2 };
int dy[8] = { 1,-1,2,-2,2,-2,1,-1 };
int board[4][4];
bool vis[4][4];
int ans = 0;

void solve(int x, int y, int score) {
    if (x == n) {
        ans = max(ans, score);
        return;
    }
    if (y == n) {
        solve(x + 1, 0, score);
        return;
    }

    solve(x, y + 1, score);

    bool canPlace = true;
    for (int dir = 0; dir < 8; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if (vis[nx][ny]) {
            canPlace = false;
            break;
        }
    }

    if (canPlace) {
        vis[x][y] = true;
        solve(x, y + 1, score + board[x][y]);
        vis[x][y] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    solve(0, 0, 0);
    cout << ans << '\n';

    return 0;
}